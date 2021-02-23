use crate::bindings;
use crate::BytePtr;
use crate::Ptr;

impl From<lib_ruby_parser::Token> for Ptr<bindings::Token> {
    fn from(token: lib_ruby_parser::Token) -> Self {
        let ptr = unsafe {
            bindings::make_token(
                token.token_type,
                BytePtr::from(token.token_value),
                Ptr::<bindings::Loc>::from(token.loc).unwrap(),
            )
        };

        Ptr::new(ptr)
    }
}
