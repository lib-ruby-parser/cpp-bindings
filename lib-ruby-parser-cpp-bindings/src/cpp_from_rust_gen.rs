use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

impl From<lib_ruby_parser::nodes::Alias> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Alias) -> Self {
        let lib_ruby_parser::nodes::Alias { to, from, keyword_l, expression_l } = node;
        let to = Ptr::<bindings::Node>::from(to).unwrap();
        let from = Ptr::<bindings::Node>::from(from).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_alias(to, from, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::AndAsgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::AndAsgn) -> Self {
        let lib_ruby_parser::nodes::AndAsgn { recv, value, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_and_asgn(recv, value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::And> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::And) -> Self {
        let lib_ruby_parser::nodes::And { lhs, rhs, operator_l, expression_l } = node;
        let lhs = Ptr::<bindings::Node>::from(lhs).unwrap();
        let rhs = Ptr::<bindings::Node>::from(rhs).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_and(lhs, rhs, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Arg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Arg) -> Self {
        let lib_ruby_parser::nodes::Arg { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_arg(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Args> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Args) -> Self {
        let lib_ruby_parser::nodes::Args { args, expression_l, begin_l, end_l } = node;
        let args = bindings::NodeVec::from(args);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let ptr = unsafe {
            bindings::make_args(args, expression_l, begin_l, end_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Array> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Array) -> Self {
        let lib_ruby_parser::nodes::Array { elements, begin_l, end_l, expression_l } = node;
        let elements = bindings::NodeVec::from(elements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_array(elements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ArrayPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ArrayPattern) -> Self {
        let lib_ruby_parser::nodes::ArrayPattern { elements, begin_l, end_l, expression_l } = node;
        let elements = bindings::NodeVec::from(elements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_array_pattern(elements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ArrayPatternWithTail> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ArrayPatternWithTail) -> Self {
        let lib_ruby_parser::nodes::ArrayPatternWithTail { elements, begin_l, end_l, expression_l } = node;
        let elements = bindings::NodeVec::from(elements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_array_pattern_with_tail(elements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::BackRef> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::BackRef) -> Self {
        let lib_ruby_parser::nodes::BackRef { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_back_ref(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Begin> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Begin) -> Self {
        let lib_ruby_parser::nodes::Begin { statements, begin_l, end_l, expression_l } = node;
        let statements = bindings::NodeVec::from(statements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_begin(statements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Block> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Block) -> Self {
        let lib_ruby_parser::nodes::Block { call, args, body, begin_l, end_l, expression_l } = node;
        let call = Ptr::<bindings::Node>::from(call).unwrap();
        let args = Ptr::<bindings::Node>::from(args).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_block(call, args, body, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::BlockPass> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::BlockPass) -> Self {
        let lib_ruby_parser::nodes::BlockPass { value, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_block_pass(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Blockarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Blockarg) -> Self {
        let lib_ruby_parser::nodes::Blockarg { name, operator_l, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_blockarg(name, operator_l, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Break> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Break) -> Self {
        let lib_ruby_parser::nodes::Break { args, keyword_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_break_(args, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Case> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Case) -> Self {
        let lib_ruby_parser::nodes::Case { expr, when_bodies, else_body, keyword_l, else_l, end_l, expression_l } = node;
        let expr = Ptr::<bindings::Node>::from(expr).unwrap();
        let when_bodies = bindings::NodeVec::from(when_bodies);
        let else_body = Ptr::<bindings::Node>::from(else_body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let else_l = Ptr::<bindings::Range>::from(else_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_case(expr, when_bodies, else_body, keyword_l, else_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::CaseMatch> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::CaseMatch) -> Self {
        let lib_ruby_parser::nodes::CaseMatch { expr, in_bodies, else_body, keyword_l, else_l, end_l, expression_l } = node;
        let expr = Ptr::<bindings::Node>::from(expr).unwrap();
        let in_bodies = bindings::NodeVec::from(in_bodies);
        let else_body = Ptr::<bindings::Node>::from(else_body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let else_l = Ptr::<bindings::Range>::from(else_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_case_match(expr, in_bodies, else_body, keyword_l, else_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Casgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Casgn) -> Self {
        let lib_ruby_parser::nodes::Casgn { scope, name, value, double_colon_l, name_l, operator_l, expression_l } = node;
        let scope = Ptr::<bindings::Node>::from(scope).unwrap();
        let name = BytePtr::from(name);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let double_colon_l = Ptr::<bindings::Range>::from(double_colon_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_casgn(scope, name, value, double_colon_l, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Cbase> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Cbase) -> Self {
        let lib_ruby_parser::nodes::Cbase { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_cbase(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Class> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Class) -> Self {
        let lib_ruby_parser::nodes::Class { name, superclass, body, keyword_l, operator_l, end_l, expression_l } = node;
        let name = Ptr::<bindings::Node>::from(name).unwrap();
        let superclass = Ptr::<bindings::Node>::from(superclass).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_class(name, superclass, body, keyword_l, operator_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Complex> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Complex) -> Self {
        let lib_ruby_parser::nodes::Complex { value, operator_l, expression_l } = node;
        let value = BytePtr::from(value);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_complex(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Const> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Const) -> Self {
        let lib_ruby_parser::nodes::Const { scope, name, double_colon_l, name_l, expression_l } = node;
        let scope = Ptr::<bindings::Node>::from(scope).unwrap();
        let name = BytePtr::from(name);
        let double_colon_l = Ptr::<bindings::Range>::from(double_colon_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_const_(scope, name, double_colon_l, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ConstPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ConstPattern) -> Self {
        let lib_ruby_parser::nodes::ConstPattern { const_, pattern, begin_l, end_l, expression_l } = node;
        let const_ = Ptr::<bindings::Node>::from(const_).unwrap();
        let pattern = Ptr::<bindings::Node>::from(pattern).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_const_pattern(const_, pattern, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::CSend> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::CSend) -> Self {
        let lib_ruby_parser::nodes::CSend { recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let method_name = BytePtr::from(method_name);
        let args = bindings::NodeVec::from(args);
        let dot_l = Ptr::<bindings::Range>::from(dot_l).unwrap();
        let selector_l = Ptr::<bindings::Range>::from(selector_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_csend(recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Cvar> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Cvar) -> Self {
        let lib_ruby_parser::nodes::Cvar { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_cvar(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Cvasgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Cvasgn) -> Self {
        let lib_ruby_parser::nodes::Cvasgn { name, value, name_l, operator_l, expression_l } = node;
        let name = BytePtr::from(name);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_cvasgn(name, value, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Def> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Def) -> Self {
        let lib_ruby_parser::nodes::Def { name, args, body, keyword_l, name_l, end_l, assignment_l, expression_l } = node;
        let name = BytePtr::from(name);
        let args = Ptr::<bindings::Node>::from(args).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let assignment_l = Ptr::<bindings::Range>::from(assignment_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_def(name, args, body, keyword_l, name_l, end_l, assignment_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Defined> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Defined) -> Self {
        let lib_ruby_parser::nodes::Defined { value, keyword_l, begin_l, end_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_defined(value, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Defs> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Defs) -> Self {
        let lib_ruby_parser::nodes::Defs { definee, name, args, body, keyword_l, operator_l, name_l, assignment_l, end_l, expression_l } = node;
        let definee = Ptr::<bindings::Node>::from(definee).unwrap();
        let name = BytePtr::from(name);
        let args = Ptr::<bindings::Node>::from(args).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let assignment_l = Ptr::<bindings::Range>::from(assignment_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_defs(definee, name, args, body, keyword_l, operator_l, name_l, assignment_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Dstr> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Dstr) -> Self {
        let lib_ruby_parser::nodes::Dstr { parts, begin_l, end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_dstr(parts, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Dsym> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Dsym) -> Self {
        let lib_ruby_parser::nodes::Dsym { parts, begin_l, end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_dsym(parts, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::EFlipFlop> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::EFlipFlop) -> Self {
        let lib_ruby_parser::nodes::EFlipFlop { left, right, operator_l, expression_l } = node;
        let left = Ptr::<bindings::Node>::from(left).unwrap();
        let right = Ptr::<bindings::Node>::from(right).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_eflipflop(left, right, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::EmptyElse> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::EmptyElse) -> Self {
        let lib_ruby_parser::nodes::EmptyElse { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_empty_else(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Encoding> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Encoding) -> Self {
        let lib_ruby_parser::nodes::Encoding { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_encoding_(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Ensure> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Ensure) -> Self {
        let lib_ruby_parser::nodes::Ensure { body, ensure, keyword_l, expression_l } = node;
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let ensure = Ptr::<bindings::Node>::from(ensure).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_ensure(body, ensure, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Erange> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Erange) -> Self {
        let lib_ruby_parser::nodes::Erange { left, right, operator_l, expression_l } = node;
        let left = Ptr::<bindings::Node>::from(left).unwrap();
        let right = Ptr::<bindings::Node>::from(right).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_erange(left, right, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::False> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::False) -> Self {
        let lib_ruby_parser::nodes::False { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_false_(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::File> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::File) -> Self {
        let lib_ruby_parser::nodes::File { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_file(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::FindPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::FindPattern) -> Self {
        let lib_ruby_parser::nodes::FindPattern { elements, begin_l, end_l, expression_l } = node;
        let elements = bindings::NodeVec::from(elements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_find_pattern(elements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Float> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Float) -> Self {
        let lib_ruby_parser::nodes::Float { value, operator_l, expression_l } = node;
        let value = BytePtr::from(value);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_float(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::For> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::For) -> Self {
        let lib_ruby_parser::nodes::For { iterator, iteratee, body, keyword_l, operator_l, begin_l, end_l, expression_l } = node;
        let iterator = Ptr::<bindings::Node>::from(iterator).unwrap();
        let iteratee = Ptr::<bindings::Node>::from(iteratee).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_for_(iterator, iteratee, body, keyword_l, operator_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ForwardArg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ForwardArg) -> Self {
        let lib_ruby_parser::nodes::ForwardArg { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_forward_arg(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ForwardedArgs> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ForwardedArgs) -> Self {
        let lib_ruby_parser::nodes::ForwardedArgs { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_forwarded_args(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Gvar> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Gvar) -> Self {
        let lib_ruby_parser::nodes::Gvar { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_gvar(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Gvasgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Gvasgn) -> Self {
        let lib_ruby_parser::nodes::Gvasgn { name, value, name_l, operator_l, expression_l } = node;
        let name = BytePtr::from(name);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_gvasgn(name, value, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Hash> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Hash) -> Self {
        let lib_ruby_parser::nodes::Hash { pairs, begin_l, end_l, expression_l } = node;
        let pairs = bindings::NodeVec::from(pairs);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_hash(pairs, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwargs> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwargs) -> Self {
        let lib_ruby_parser::nodes::Kwargs { pairs, expression_l } = node;
        let pairs = bindings::NodeVec::from(pairs);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwargs(pairs, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::HashPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::HashPattern) -> Self {
        let lib_ruby_parser::nodes::HashPattern { elements, begin_l, end_l, expression_l } = node;
        let elements = bindings::NodeVec::from(elements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_hash_pattern(elements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Heredoc> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Heredoc) -> Self {
        let lib_ruby_parser::nodes::Heredoc { parts, heredoc_body_l, heredoc_end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let heredoc_body_l = Ptr::<bindings::Range>::from(heredoc_body_l).unwrap();
        let heredoc_end_l = Ptr::<bindings::Range>::from(heredoc_end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_heredoc(parts, heredoc_body_l, heredoc_end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::If> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::If) -> Self {
        let lib_ruby_parser::nodes::If { cond, if_true, if_false, keyword_l, begin_l, else_l, end_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let if_true = Ptr::<bindings::Node>::from(if_true).unwrap();
        let if_false = Ptr::<bindings::Node>::from(if_false).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let else_l = Ptr::<bindings::Range>::from(else_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_if_(cond, if_true, if_false, keyword_l, begin_l, else_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::IfGuard> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::IfGuard) -> Self {
        let lib_ruby_parser::nodes::IfGuard { cond, keyword_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_if_guard(cond, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::IfMod> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::IfMod) -> Self {
        let lib_ruby_parser::nodes::IfMod { cond, if_true, if_false, keyword_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let if_true = Ptr::<bindings::Node>::from(if_true).unwrap();
        let if_false = Ptr::<bindings::Node>::from(if_false).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_if_mod(cond, if_true, if_false, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::IfTernary> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::IfTernary) -> Self {
        let lib_ruby_parser::nodes::IfTernary { cond, if_true, if_false, question_l, colon_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let if_true = Ptr::<bindings::Node>::from(if_true).unwrap();
        let if_false = Ptr::<bindings::Node>::from(if_false).unwrap();
        let question_l = Ptr::<bindings::Range>::from(question_l).unwrap();
        let colon_l = Ptr::<bindings::Range>::from(colon_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_if_ternary(cond, if_true, if_false, question_l, colon_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::IFlipFlop> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::IFlipFlop) -> Self {
        let lib_ruby_parser::nodes::IFlipFlop { left, right, operator_l, expression_l } = node;
        let left = Ptr::<bindings::Node>::from(left).unwrap();
        let right = Ptr::<bindings::Node>::from(right).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_iflipflop(left, right, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchPattern) -> Self {
        let lib_ruby_parser::nodes::MatchPattern { value, pattern, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let pattern = Ptr::<bindings::Node>::from(pattern).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_pattern(value, pattern, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchPatternP> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchPatternP) -> Self {
        let lib_ruby_parser::nodes::MatchPatternP { value, pattern, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let pattern = Ptr::<bindings::Node>::from(pattern).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_pattern_p(value, pattern, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::InPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::InPattern) -> Self {
        let lib_ruby_parser::nodes::InPattern { pattern, guard, body, keyword_l, begin_l, expression_l } = node;
        let pattern = Ptr::<bindings::Node>::from(pattern).unwrap();
        let guard = Ptr::<bindings::Node>::from(guard).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_in_pattern(pattern, guard, body, keyword_l, begin_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Index> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Index) -> Self {
        let lib_ruby_parser::nodes::Index { recv, indexes, begin_l, end_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let indexes = bindings::NodeVec::from(indexes);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_index(recv, indexes, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::IndexAsgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::IndexAsgn) -> Self {
        let lib_ruby_parser::nodes::IndexAsgn { recv, indexes, value, begin_l, end_l, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let indexes = bindings::NodeVec::from(indexes);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_index_asgn(recv, indexes, value, begin_l, end_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Int> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Int) -> Self {
        let lib_ruby_parser::nodes::Int { value, operator_l, expression_l } = node;
        let value = BytePtr::from(value);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_int(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Irange> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Irange) -> Self {
        let lib_ruby_parser::nodes::Irange { left, right, operator_l, expression_l } = node;
        let left = Ptr::<bindings::Node>::from(left).unwrap();
        let right = Ptr::<bindings::Node>::from(right).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_irange(left, right, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Ivar> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Ivar) -> Self {
        let lib_ruby_parser::nodes::Ivar { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_ivar(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Ivasgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Ivasgn) -> Self {
        let lib_ruby_parser::nodes::Ivasgn { name, value, name_l, operator_l, expression_l } = node;
        let name = BytePtr::from(name);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_ivasgn(name, value, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwarg) -> Self {
        let lib_ruby_parser::nodes::Kwarg { name, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwarg(name, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::KwBegin> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::KwBegin) -> Self {
        let lib_ruby_parser::nodes::KwBegin { statements, begin_l, end_l, expression_l } = node;
        let statements = bindings::NodeVec::from(statements);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwbegin(statements, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwnilarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwnilarg) -> Self {
        let lib_ruby_parser::nodes::Kwnilarg { name_l, expression_l } = node;
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwnilarg(name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwoptarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwoptarg) -> Self {
        let lib_ruby_parser::nodes::Kwoptarg { name, default, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let default = Ptr::<bindings::Node>::from(default).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwoptarg(name, default, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwrestarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwrestarg) -> Self {
        let lib_ruby_parser::nodes::Kwrestarg { name, operator_l, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwrestarg(name, operator_l, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Kwsplat> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Kwsplat) -> Self {
        let lib_ruby_parser::nodes::Kwsplat { value, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_kwsplat(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Lambda> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Lambda) -> Self {
        let lib_ruby_parser::nodes::Lambda { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_lambda(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Line> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Line) -> Self {
        let lib_ruby_parser::nodes::Line { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_line(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Lvar> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Lvar) -> Self {
        let lib_ruby_parser::nodes::Lvar { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_lvar(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Lvasgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Lvasgn) -> Self {
        let lib_ruby_parser::nodes::Lvasgn { name, value, name_l, operator_l, expression_l } = node;
        let name = BytePtr::from(name);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_lvasgn(name, value, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Masgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Masgn) -> Self {
        let lib_ruby_parser::nodes::Masgn { lhs, rhs, operator_l, expression_l } = node;
        let lhs = Ptr::<bindings::Node>::from(lhs).unwrap();
        let rhs = Ptr::<bindings::Node>::from(rhs).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_masgn(lhs, rhs, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchAlt> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchAlt) -> Self {
        let lib_ruby_parser::nodes::MatchAlt { lhs, rhs, operator_l, expression_l } = node;
        let lhs = Ptr::<bindings::Node>::from(lhs).unwrap();
        let rhs = Ptr::<bindings::Node>::from(rhs).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_alt(lhs, rhs, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchAs> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchAs) -> Self {
        let lib_ruby_parser::nodes::MatchAs { value, as_, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let as_ = Ptr::<bindings::Node>::from(as_).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_as(value, as_, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchCurrentLine> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchCurrentLine) -> Self {
        let lib_ruby_parser::nodes::MatchCurrentLine { re, expression_l } = node;
        let re = Ptr::<bindings::Node>::from(re).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_current_line(re, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchNilPattern> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchNilPattern) -> Self {
        let lib_ruby_parser::nodes::MatchNilPattern { operator_l, name_l, expression_l } = node;
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_nil_pattern(operator_l, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchRest> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchRest) -> Self {
        let lib_ruby_parser::nodes::MatchRest { name, operator_l, expression_l } = node;
        let name = Ptr::<bindings::Node>::from(name).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_rest(name, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchVar> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchVar) -> Self {
        let lib_ruby_parser::nodes::MatchVar { name, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_var(name, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::MatchWithLvasgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::MatchWithLvasgn) -> Self {
        let lib_ruby_parser::nodes::MatchWithLvasgn { re, value, operator_l, expression_l } = node;
        let re = Ptr::<bindings::Node>::from(re).unwrap();
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_match_with_lvasgn(re, value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Mlhs> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Mlhs) -> Self {
        let lib_ruby_parser::nodes::Mlhs { items, begin_l, end_l, expression_l } = node;
        let items = bindings::NodeVec::from(items);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_mlhs(items, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Module> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Module) -> Self {
        let lib_ruby_parser::nodes::Module { name, body, keyword_l, end_l, expression_l } = node;
        let name = Ptr::<bindings::Node>::from(name).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_module(name, body, keyword_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Next> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Next) -> Self {
        let lib_ruby_parser::nodes::Next { args, keyword_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_next(args, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Nil> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Nil) -> Self {
        let lib_ruby_parser::nodes::Nil { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_nil(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::NthRef> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::NthRef) -> Self {
        let lib_ruby_parser::nodes::NthRef { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_nth_ref(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Numblock> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Numblock) -> Self {
        let lib_ruby_parser::nodes::Numblock { call, numargs, body, begin_l, end_l, expression_l } = node;
        let call = Ptr::<bindings::Node>::from(call).unwrap();
        let numargs = numargs as bindings::size_t;
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_numblock(call, numargs, body, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::OpAsgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::OpAsgn) -> Self {
        let lib_ruby_parser::nodes::OpAsgn { recv, operator, value, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let operator = BytePtr::from(operator);
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_op_asgn(recv, operator, value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Optarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Optarg) -> Self {
        let lib_ruby_parser::nodes::Optarg { name, default, name_l, operator_l, expression_l } = node;
        let name = BytePtr::from(name);
        let default = Ptr::<bindings::Node>::from(default).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_optarg(name, default, name_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Or> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Or) -> Self {
        let lib_ruby_parser::nodes::Or { lhs, rhs, operator_l, expression_l } = node;
        let lhs = Ptr::<bindings::Node>::from(lhs).unwrap();
        let rhs = Ptr::<bindings::Node>::from(rhs).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_or(lhs, rhs, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::OrAsgn> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::OrAsgn) -> Self {
        let lib_ruby_parser::nodes::OrAsgn { recv, value, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_or_asgn(recv, value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Pair> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Pair) -> Self {
        let lib_ruby_parser::nodes::Pair { key, value, operator_l, expression_l } = node;
        let key = Ptr::<bindings::Node>::from(key).unwrap();
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_pair(key, value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Pin> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Pin) -> Self {
        let lib_ruby_parser::nodes::Pin { var, selector_l, expression_l } = node;
        let var = Ptr::<bindings::Node>::from(var).unwrap();
        let selector_l = Ptr::<bindings::Range>::from(selector_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_pin(var, selector_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Postexe> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Postexe) -> Self {
        let lib_ruby_parser::nodes::Postexe { body, keyword_l, begin_l, end_l, expression_l } = node;
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_postexe(body, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Preexe> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Preexe) -> Self {
        let lib_ruby_parser::nodes::Preexe { body, keyword_l, begin_l, end_l, expression_l } = node;
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_preexe(body, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Procarg0> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Procarg0) -> Self {
        let lib_ruby_parser::nodes::Procarg0 { args, begin_l, end_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_procarg0(args, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Rational> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Rational) -> Self {
        let lib_ruby_parser::nodes::Rational { value, operator_l, expression_l } = node;
        let value = BytePtr::from(value);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_rational(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Redo> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Redo) -> Self {
        let lib_ruby_parser::nodes::Redo { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_redo(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::RegOpt> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::RegOpt) -> Self {
        let lib_ruby_parser::nodes::RegOpt { options, expression_l } = node;
        let options = BytePtr::from(options);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_reg_opt(options, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Regexp> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Regexp) -> Self {
        let lib_ruby_parser::nodes::Regexp { parts, options, begin_l, end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let options = Ptr::<bindings::Node>::from(options).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_regexp(parts, options, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Rescue> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Rescue) -> Self {
        let lib_ruby_parser::nodes::Rescue { body, rescue_bodies, else_, else_l, expression_l } = node;
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let rescue_bodies = bindings::NodeVec::from(rescue_bodies);
        let else_ = Ptr::<bindings::Node>::from(else_).unwrap();
        let else_l = Ptr::<bindings::Range>::from(else_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_rescue(body, rescue_bodies, else_, else_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::RescueBody> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::RescueBody) -> Self {
        let lib_ruby_parser::nodes::RescueBody { exc_list, exc_var, body, keyword_l, assoc_l, begin_l, expression_l } = node;
        let exc_list = Ptr::<bindings::Node>::from(exc_list).unwrap();
        let exc_var = Ptr::<bindings::Node>::from(exc_var).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let assoc_l = Ptr::<bindings::Range>::from(assoc_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_rescue_body(exc_list, exc_var, body, keyword_l, assoc_l, begin_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Restarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Restarg) -> Self {
        let lib_ruby_parser::nodes::Restarg { name, operator_l, name_l, expression_l } = node;
        let name = BytePtr::from(name);
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let name_l = Ptr::<bindings::Range>::from(name_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_restarg(name, operator_l, name_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Retry> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Retry) -> Self {
        let lib_ruby_parser::nodes::Retry { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_retry(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Return> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Return) -> Self {
        let lib_ruby_parser::nodes::Return { args, keyword_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_return_(args, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::SClass> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::SClass) -> Self {
        let lib_ruby_parser::nodes::SClass { expr, body, keyword_l, operator_l, end_l, expression_l } = node;
        let expr = Ptr::<bindings::Node>::from(expr).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_sclass(expr, body, keyword_l, operator_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Self_> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Self_) -> Self {
        let lib_ruby_parser::nodes::Self_ { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_self_(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Send> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Send) -> Self {
        let lib_ruby_parser::nodes::Send { recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l } = node;
        let recv = Ptr::<bindings::Node>::from(recv).unwrap();
        let method_name = BytePtr::from(method_name);
        let args = bindings::NodeVec::from(args);
        let dot_l = Ptr::<bindings::Range>::from(dot_l).unwrap();
        let selector_l = Ptr::<bindings::Range>::from(selector_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_send(recv, method_name, args, dot_l, selector_l, begin_l, end_l, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Shadowarg> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Shadowarg) -> Self {
        let lib_ruby_parser::nodes::Shadowarg { name, expression_l } = node;
        let name = BytePtr::from(name);
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_shadowarg(name, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Splat> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Splat) -> Self {
        let lib_ruby_parser::nodes::Splat { value, operator_l, expression_l } = node;
        let value = Ptr::<bindings::Node>::from(value).unwrap();
        let operator_l = Ptr::<bindings::Range>::from(operator_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_splat(value, operator_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Str> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Str) -> Self {
        let lib_ruby_parser::nodes::Str { value, begin_l, end_l, expression_l } = node;
        let value = BytePtr::from(value);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_str_(value, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Super> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Super) -> Self {
        let lib_ruby_parser::nodes::Super { args, keyword_l, begin_l, end_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_super_(args, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Sym> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Sym) -> Self {
        let lib_ruby_parser::nodes::Sym { name, begin_l, end_l, expression_l } = node;
        let name = BytePtr::from(name);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_sym(name, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::True> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::True) -> Self {
        let lib_ruby_parser::nodes::True { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_true_(expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Undef> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Undef) -> Self {
        let lib_ruby_parser::nodes::Undef { names, keyword_l, expression_l } = node;
        let names = bindings::NodeVec::from(names);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_undef(names, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::UnlessGuard> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::UnlessGuard) -> Self {
        let lib_ruby_parser::nodes::UnlessGuard { cond, keyword_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_unless_guard(cond, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Until> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Until) -> Self {
        let lib_ruby_parser::nodes::Until { cond, body, keyword_l, begin_l, end_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_until(cond, body, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::UntilPost> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::UntilPost) -> Self {
        let lib_ruby_parser::nodes::UntilPost { cond, body, keyword_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_until_post(cond, body, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::When> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::When) -> Self {
        let lib_ruby_parser::nodes::When { patterns, body, keyword_l, begin_l, expression_l } = node;
        let patterns = bindings::NodeVec::from(patterns);
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_when(patterns, body, keyword_l, begin_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::While> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::While) -> Self {
        let lib_ruby_parser::nodes::While { cond, body, keyword_l, begin_l, end_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_while_(cond, body, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::WhilePost> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::WhilePost) -> Self {
        let lib_ruby_parser::nodes::WhilePost { cond, body, keyword_l, expression_l } = node;
        let cond = Ptr::<bindings::Node>::from(cond).unwrap();
        let body = Ptr::<bindings::Node>::from(body).unwrap();
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_while_post(cond, body, keyword_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::XHeredoc> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::XHeredoc) -> Self {
        let lib_ruby_parser::nodes::XHeredoc { parts, heredoc_body_l, heredoc_end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let heredoc_body_l = Ptr::<bindings::Range>::from(heredoc_body_l).unwrap();
        let heredoc_end_l = Ptr::<bindings::Range>::from(heredoc_end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_x_heredoc(parts, heredoc_body_l, heredoc_end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Xstr> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Xstr) -> Self {
        let lib_ruby_parser::nodes::Xstr { parts, begin_l, end_l, expression_l } = node;
        let parts = bindings::NodeVec::from(parts);
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_xstr(parts, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::Yield> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::Yield) -> Self {
        let lib_ruby_parser::nodes::Yield { args, keyword_l, begin_l, end_l, expression_l } = node;
        let args = bindings::NodeVec::from(args);
        let keyword_l = Ptr::<bindings::Range>::from(keyword_l).unwrap();
        let begin_l = Ptr::<bindings::Range>::from(begin_l).unwrap();
        let end_l = Ptr::<bindings::Range>::from(end_l).unwrap();
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_yield_(args, keyword_l, begin_l, end_l, expression_l)
        };
        Ptr::new(ptr)
    }
}

impl From<lib_ruby_parser::nodes::ZSuper> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::nodes::ZSuper) -> Self {
        let lib_ruby_parser::nodes::ZSuper { expression_l } = node;
        let expression_l = Ptr::<bindings::Range>::from(expression_l).unwrap();
        let ptr = unsafe {
            bindings::make_zsuper(expression_l)
        };
        Ptr::new(ptr)
    }
}


impl From<lib_ruby_parser::Node> for Ptr<bindings::Node> {
    fn from(node: lib_ruby_parser::Node) -> Self {
        match node {
            lib_ruby_parser::Node::Alias(inner) => inner.into(),
            lib_ruby_parser::Node::AndAsgn(inner) => inner.into(),
            lib_ruby_parser::Node::And(inner) => inner.into(),
            lib_ruby_parser::Node::Arg(inner) => inner.into(),
            lib_ruby_parser::Node::Args(inner) => inner.into(),
            lib_ruby_parser::Node::Array(inner) => inner.into(),
            lib_ruby_parser::Node::ArrayPattern(inner) => inner.into(),
            lib_ruby_parser::Node::ArrayPatternWithTail(inner) => inner.into(),
            lib_ruby_parser::Node::BackRef(inner) => inner.into(),
            lib_ruby_parser::Node::Begin(inner) => inner.into(),
            lib_ruby_parser::Node::Block(inner) => inner.into(),
            lib_ruby_parser::Node::BlockPass(inner) => inner.into(),
            lib_ruby_parser::Node::Blockarg(inner) => inner.into(),
            lib_ruby_parser::Node::Break(inner) => inner.into(),
            lib_ruby_parser::Node::Case(inner) => inner.into(),
            lib_ruby_parser::Node::CaseMatch(inner) => inner.into(),
            lib_ruby_parser::Node::Casgn(inner) => inner.into(),
            lib_ruby_parser::Node::Cbase(inner) => inner.into(),
            lib_ruby_parser::Node::Class(inner) => inner.into(),
            lib_ruby_parser::Node::Complex(inner) => inner.into(),
            lib_ruby_parser::Node::Const(inner) => inner.into(),
            lib_ruby_parser::Node::ConstPattern(inner) => inner.into(),
            lib_ruby_parser::Node::CSend(inner) => inner.into(),
            lib_ruby_parser::Node::Cvar(inner) => inner.into(),
            lib_ruby_parser::Node::Cvasgn(inner) => inner.into(),
            lib_ruby_parser::Node::Def(inner) => inner.into(),
            lib_ruby_parser::Node::Defined(inner) => inner.into(),
            lib_ruby_parser::Node::Defs(inner) => inner.into(),
            lib_ruby_parser::Node::Dstr(inner) => inner.into(),
            lib_ruby_parser::Node::Dsym(inner) => inner.into(),
            lib_ruby_parser::Node::EFlipFlop(inner) => inner.into(),
            lib_ruby_parser::Node::EmptyElse(inner) => inner.into(),
            lib_ruby_parser::Node::Encoding(inner) => inner.into(),
            lib_ruby_parser::Node::Ensure(inner) => inner.into(),
            lib_ruby_parser::Node::Erange(inner) => inner.into(),
            lib_ruby_parser::Node::False(inner) => inner.into(),
            lib_ruby_parser::Node::File(inner) => inner.into(),
            lib_ruby_parser::Node::FindPattern(inner) => inner.into(),
            lib_ruby_parser::Node::Float(inner) => inner.into(),
            lib_ruby_parser::Node::For(inner) => inner.into(),
            lib_ruby_parser::Node::ForwardArg(inner) => inner.into(),
            lib_ruby_parser::Node::ForwardedArgs(inner) => inner.into(),
            lib_ruby_parser::Node::Gvar(inner) => inner.into(),
            lib_ruby_parser::Node::Gvasgn(inner) => inner.into(),
            lib_ruby_parser::Node::Hash(inner) => inner.into(),
            lib_ruby_parser::Node::Kwargs(inner) => inner.into(),
            lib_ruby_parser::Node::HashPattern(inner) => inner.into(),
            lib_ruby_parser::Node::Heredoc(inner) => inner.into(),
            lib_ruby_parser::Node::If(inner) => inner.into(),
            lib_ruby_parser::Node::IfGuard(inner) => inner.into(),
            lib_ruby_parser::Node::IfMod(inner) => inner.into(),
            lib_ruby_parser::Node::IfTernary(inner) => inner.into(),
            lib_ruby_parser::Node::IFlipFlop(inner) => inner.into(),
            lib_ruby_parser::Node::MatchPattern(inner) => inner.into(),
            lib_ruby_parser::Node::MatchPatternP(inner) => inner.into(),
            lib_ruby_parser::Node::InPattern(inner) => inner.into(),
            lib_ruby_parser::Node::Index(inner) => inner.into(),
            lib_ruby_parser::Node::IndexAsgn(inner) => inner.into(),
            lib_ruby_parser::Node::Int(inner) => inner.into(),
            lib_ruby_parser::Node::Irange(inner) => inner.into(),
            lib_ruby_parser::Node::Ivar(inner) => inner.into(),
            lib_ruby_parser::Node::Ivasgn(inner) => inner.into(),
            lib_ruby_parser::Node::Kwarg(inner) => inner.into(),
            lib_ruby_parser::Node::KwBegin(inner) => inner.into(),
            lib_ruby_parser::Node::Kwnilarg(inner) => inner.into(),
            lib_ruby_parser::Node::Kwoptarg(inner) => inner.into(),
            lib_ruby_parser::Node::Kwrestarg(inner) => inner.into(),
            lib_ruby_parser::Node::Kwsplat(inner) => inner.into(),
            lib_ruby_parser::Node::Lambda(inner) => inner.into(),
            lib_ruby_parser::Node::Line(inner) => inner.into(),
            lib_ruby_parser::Node::Lvar(inner) => inner.into(),
            lib_ruby_parser::Node::Lvasgn(inner) => inner.into(),
            lib_ruby_parser::Node::Masgn(inner) => inner.into(),
            lib_ruby_parser::Node::MatchAlt(inner) => inner.into(),
            lib_ruby_parser::Node::MatchAs(inner) => inner.into(),
            lib_ruby_parser::Node::MatchCurrentLine(inner) => inner.into(),
            lib_ruby_parser::Node::MatchNilPattern(inner) => inner.into(),
            lib_ruby_parser::Node::MatchRest(inner) => inner.into(),
            lib_ruby_parser::Node::MatchVar(inner) => inner.into(),
            lib_ruby_parser::Node::MatchWithLvasgn(inner) => inner.into(),
            lib_ruby_parser::Node::Mlhs(inner) => inner.into(),
            lib_ruby_parser::Node::Module(inner) => inner.into(),
            lib_ruby_parser::Node::Next(inner) => inner.into(),
            lib_ruby_parser::Node::Nil(inner) => inner.into(),
            lib_ruby_parser::Node::NthRef(inner) => inner.into(),
            lib_ruby_parser::Node::Numblock(inner) => inner.into(),
            lib_ruby_parser::Node::OpAsgn(inner) => inner.into(),
            lib_ruby_parser::Node::Optarg(inner) => inner.into(),
            lib_ruby_parser::Node::Or(inner) => inner.into(),
            lib_ruby_parser::Node::OrAsgn(inner) => inner.into(),
            lib_ruby_parser::Node::Pair(inner) => inner.into(),
            lib_ruby_parser::Node::Pin(inner) => inner.into(),
            lib_ruby_parser::Node::Postexe(inner) => inner.into(),
            lib_ruby_parser::Node::Preexe(inner) => inner.into(),
            lib_ruby_parser::Node::Procarg0(inner) => inner.into(),
            lib_ruby_parser::Node::Rational(inner) => inner.into(),
            lib_ruby_parser::Node::Redo(inner) => inner.into(),
            lib_ruby_parser::Node::RegOpt(inner) => inner.into(),
            lib_ruby_parser::Node::Regexp(inner) => inner.into(),
            lib_ruby_parser::Node::Rescue(inner) => inner.into(),
            lib_ruby_parser::Node::RescueBody(inner) => inner.into(),
            lib_ruby_parser::Node::Restarg(inner) => inner.into(),
            lib_ruby_parser::Node::Retry(inner) => inner.into(),
            lib_ruby_parser::Node::Return(inner) => inner.into(),
            lib_ruby_parser::Node::SClass(inner) => inner.into(),
            lib_ruby_parser::Node::Self_(inner) => inner.into(),
            lib_ruby_parser::Node::Send(inner) => inner.into(),
            lib_ruby_parser::Node::Shadowarg(inner) => inner.into(),
            lib_ruby_parser::Node::Splat(inner) => inner.into(),
            lib_ruby_parser::Node::Str(inner) => inner.into(),
            lib_ruby_parser::Node::Super(inner) => inner.into(),
            lib_ruby_parser::Node::Sym(inner) => inner.into(),
            lib_ruby_parser::Node::True(inner) => inner.into(),
            lib_ruby_parser::Node::Undef(inner) => inner.into(),
            lib_ruby_parser::Node::UnlessGuard(inner) => inner.into(),
            lib_ruby_parser::Node::Until(inner) => inner.into(),
            lib_ruby_parser::Node::UntilPost(inner) => inner.into(),
            lib_ruby_parser::Node::When(inner) => inner.into(),
            lib_ruby_parser::Node::While(inner) => inner.into(),
            lib_ruby_parser::Node::WhilePost(inner) => inner.into(),
            lib_ruby_parser::Node::XHeredoc(inner) => inner.into(),
            lib_ruby_parser::Node::Xstr(inner) => inner.into(),
            lib_ruby_parser::Node::Yield(inner) => inner.into(),
            lib_ruby_parser::Node::ZSuper(inner) => inner.into(),
        }
    }
}
