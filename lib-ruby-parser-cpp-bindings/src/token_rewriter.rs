use crate::bindings;
use crate::BytePtr;
use crate::Ptr;

struct CppTokenRewriter {
    pub(crate) rewriter: *mut bindings::TokenRewriter,
}

impl std::fmt::Debug for CppTokenRewriter {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("CppTokenRewriter").finish()
    }
}

impl From<lib_ruby_parser::Token> for bindings::RawToken {
    fn from(token: lib_ruby_parser::Token) -> Self {
        bindings::RawToken {
            token_type: token.token_type,
            token_value: BytePtr::from(token.token_value),
            loc_begin: token.loc.begin as u32,
            loc_end: token.loc.end as u32,
        }
    }
}

impl From<bindings::RawToken> for lib_ruby_parser::Token {
    fn from(token: bindings::RawToken) -> Self {
        lib_ruby_parser::Token {
            token_type: token.token_type,
            token_value: lib_ruby_parser::TokenValue::from(token.token_value),
            loc: lib_ruby_parser::Loc {
                begin: token.loc_begin as usize,
                end: token.loc_end as usize,
            },
            lex_state_before: lib_ruby_parser::LexState::default(),
            lex_state_after: lib_ruby_parser::LexState::default(),
        }
    }
}

impl From<bindings::RawRewriteAction> for lib_ruby_parser::token_rewriter::RewriteAction {
    fn from(rewrite_action: bindings::RawRewriteAction) -> Self {
        match rewrite_action {
            bindings::RawRewriteAction::REWRITE_ACTION_DROP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Drop
            }
            bindings::RawRewriteAction::REWRITE_ACTION_KEEP => {
                lib_ruby_parser::token_rewriter::RewriteAction::Keep
            }
        }
    }
}

type RewriterTuple = (
    lib_ruby_parser::Token,
    lib_ruby_parser::token_rewriter::RewriteAction,
    lib_ruby_parser::token_rewriter::LexStateAction,
);

struct RewriterResult {
    token: lib_ruby_parser::Token,
    rewrite_action: lib_ruby_parser::token_rewriter::RewriteAction,
    lex_state_action: lib_ruby_parser::token_rewriter::LexStateAction,
}

impl RewriterResult {
    pub(crate) fn to_tuple(self) -> RewriterTuple {
        (self.token, self.rewrite_action, self.lex_state_action)
    }
}

impl From<bindings::RawTokenRewriterResult> for RewriterResult {
    fn from(result: bindings::RawTokenRewriterResult) -> Self {
        let bindings::RawTokenRewriterResult {
            rewrite_action,
            lex_state_action,
            next_state,
            token,
        } = result;

        let token = lib_ruby_parser::Token::from(token);

        let rewrite_action = lib_ruby_parser::token_rewriter::RewriteAction::from(rewrite_action);

        let lex_state_action = match lex_state_action {
            bindings::RawLexStateAction::LEX_STATE_KEEP => {
                lib_ruby_parser::token_rewriter::LexStateAction::Keep
            }
            bindings::RawLexStateAction::LEX_STATE_SET => {
                lib_ruby_parser::token_rewriter::LexStateAction::Set(next_state)
            }
        };

        RewriterResult {
            token,
            rewrite_action,
            lex_state_action,
        }
    }
}

impl lib_ruby_parser::token_rewriter::TokenRewriter for CppTokenRewriter {
    fn rewrite_token(&mut self, token: lib_ruby_parser::Token, input: &[u8]) -> RewriterTuple {
        let token = bindings::RawToken::from(token);
        let input = BytePtr::from(input);

        let raw_result = unsafe { bindings::rewrite_token(self.rewriter, token, input) };
        let result = RewriterResult::from(raw_result);

        result.to_tuple()
    }
}

impl From<Ptr<bindings::TokenRewriter>>
    for Option<Box<dyn lib_ruby_parser::token_rewriter::TokenRewriter>>
{
    fn from(token_rewriter_ptr: Ptr<bindings::TokenRewriter>) -> Self {
        let token_rewriter_ptr = token_rewriter_ptr.unwrap();

        if token_rewriter_ptr.is_null() {
            return None;
        }

        Some(Box::new(CppTokenRewriter {
            rewriter: token_rewriter_ptr,
        }))
    }
}
