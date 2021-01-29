/* automatically generated by rust-bindgen */

pub type string = [u64; 3usize];
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct allocator {
    pub _address: u8,
}
pub type allocator_size_type = u64;
pub type allocator_difference_type = u64;
pub type allocator_pointer = u8;
pub type allocator_const_pointer = u8;
pub type allocator_reference = u8;
pub type allocator_const_reference = u8;
pub type allocator_value_type = u8;
pub type allocator_propagate_on_container_move_assignment = u8;
pub type allocator_is_always_equal = u8;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct allocator_rebind {
    pub _address: u8,
}
pub type allocator_rebind_other = u8;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct vector {
    pub _address: u8,
}
pub type vector___base = u8;
pub type vector___default_allocator_type = u8;
pub type vector___self = u8;
pub type vector_value_type = u8;
pub type vector_allocator_type = u8;
pub type vector___alloc_traits = u8;
pub type vector_reference = u8;
pub type vector_const_reference = u8;
pub type vector_size_type = u8;
pub type vector_difference_type = u8;
pub type vector_pointer = u8;
pub type vector_const_pointer = u8;
pub type vector_iterator = u8;
pub type vector_const_iterator = u8;
pub type vector_reverse_iterator = u8;
pub type vector_const_reverse_iterator = u8;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct vector__ConstructTransaction {
    pub _address: u8,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct BytePtr {
    pub ptr: *mut ::std::os::raw::c_char,
    pub size: u32,
}
extern "C" {
    pub fn make_byte_ptr(ptr: *const ::std::os::raw::c_char, size: u32) -> BytePtr;
}
extern "C" {
    pub fn free_byte_ptr(byte_ptr: BytePtr);
}
extern "C" {
    pub fn byte_ptr_to_utf8_lossy_byte_ptr(byte_ptr: BytePtr) -> BytePtr;
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser24byte_ptr_to_owned_stringENS_7BytePtrE"]
    pub fn byte_ptr_to_owned_string(byte_ptr: BytePtr) -> string;
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser30byte_ptr_to_owned_string_lossyENS_7BytePtrE"]
    pub fn byte_ptr_to_owned_string_lossy(byte_ptr: BytePtr) -> string;
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser15byte_ptr_to_vecENS_7BytePtrE"]
    pub fn byte_ptr_to_vec(byte_ptr: BytePtr) -> u8;
}
#[repr(C)]
#[derive(Debug)]
pub struct Bytes {
    pub bytes_: *mut ::std::os::raw::c_char,
    pub size_: u32,
    pub borrowed: bool,
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5Bytes8into_ptrEv"]
    pub fn Bytes_into_ptr(this: *mut Bytes) -> BytePtr;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes4sizeEv"]
    pub fn Bytes_size(this: *const Bytes) -> u32;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes5cloneEv"]
    pub fn Bytes_clone(this: *const Bytes) -> Bytes;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes2atEj"]
    pub fn Bytes_at(this: *const Bytes, idx: u32) -> ::std::os::raw::c_char;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes5rangeEjj"]
    pub fn Bytes_range(this: *const Bytes, begin: u32, end: u32) -> Bytes;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes9to_stringEv"]
    pub fn Bytes_to_string(this: *const Bytes) -> string;
}
extern "C" {
    #[link_name = "\u{1}__ZNK15lib_ruby_parser5Bytes15to_string_lossyEv"]
    pub fn Bytes_to_string_lossy(this: *const Bytes) -> string;
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5Bytes13mark_borrowedEv"]
    pub fn Bytes_mark_borrowed(this: *mut Bytes);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesC1Ev"]
    pub fn Bytes_Bytes(this: *mut Bytes);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesC1ENSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE"]
    pub fn Bytes_Bytes1(this: *mut Bytes, s: string);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesC1EPcj"]
    pub fn Bytes_Bytes2(this: *mut Bytes, ptr: *mut ::std::os::raw::c_char, size: u32);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesC1ENS_7BytePtrE"]
    pub fn Bytes_Bytes3(this: *mut Bytes, byte_ptr: BytePtr);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesC1EOS0_"]
    pub fn Bytes_Bytes4(this: *mut Bytes, arg1: *mut Bytes);
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser5BytesD1Ev"]
    pub fn Bytes_Bytes_destructor(this: *mut Bytes);
}
impl Bytes {
    #[inline]
    pub unsafe fn into_ptr(&mut self) -> BytePtr {
        Bytes_into_ptr(self)
    }
    #[inline]
    pub unsafe fn size(&self) -> u32 {
        Bytes_size(self)
    }
    #[inline]
    pub unsafe fn clone(&self) -> Bytes {
        Bytes_clone(self)
    }
    #[inline]
    pub unsafe fn at(&self, idx: u32) -> ::std::os::raw::c_char {
        Bytes_at(self, idx)
    }
    #[inline]
    pub unsafe fn range(&self, begin: u32, end: u32) -> Bytes {
        Bytes_range(self, begin, end)
    }
    #[inline]
    pub unsafe fn to_string(&self) -> string {
        Bytes_to_string(self)
    }
    #[inline]
    pub unsafe fn to_string_lossy(&self) -> string {
        Bytes_to_string_lossy(self)
    }
    #[inline]
    pub unsafe fn mark_borrowed(&mut self) {
        Bytes_mark_borrowed(self)
    }
    #[inline]
    pub unsafe fn new() -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        Bytes_Bytes(__bindgen_tmp.as_mut_ptr());
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn new1(s: string) -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        Bytes_Bytes1(__bindgen_tmp.as_mut_ptr(), s);
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn new2(ptr: *mut ::std::os::raw::c_char, size: u32) -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        Bytes_Bytes2(__bindgen_tmp.as_mut_ptr(), ptr, size);
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn new3(byte_ptr: BytePtr) -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        Bytes_Bytes3(__bindgen_tmp.as_mut_ptr(), byte_ptr);
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn new4(arg1: *mut Bytes) -> Self {
        let mut __bindgen_tmp = ::std::mem::MaybeUninit::uninit();
        Bytes_Bytes4(__bindgen_tmp.as_mut_ptr(), arg1);
        __bindgen_tmp.assume_init()
    }
    #[inline]
    pub unsafe fn destruct(&mut self) {
        Bytes_Bytes_destructor(self)
    }
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Node {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Range {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct NodeVec {
    pub ptr: *mut *mut Node,
    pub length: u32,
}
extern "C" {
    pub fn make_alias(
        to: *mut Node,
        from: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_and_asgn(
        recv: *mut Node,
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_and(
        lhs: *mut Node,
        rhs: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_arg(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_args(
        args: NodeVec,
        expression_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_array(
        elements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_array_pattern(
        elements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_array_pattern_with_tail(
        elements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_back_ref(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_begin(
        statements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_block(
        call: *mut Node,
        args: *mut Node,
        body: *mut Node,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_block_pass(
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_blockarg(
        name: BytePtr,
        operator_l: *mut Range,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_break_(args: NodeVec, keyword_l: *mut Range, expression_l: *mut Range)
        -> *mut Node;
}
extern "C" {
    pub fn make_case(
        expr: *mut Node,
        when_bodies: NodeVec,
        else_body: *mut Node,
        keyword_l: *mut Range,
        else_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_case_match(
        expr: *mut Node,
        in_bodies: NodeVec,
        else_body: *mut Node,
        keyword_l: *mut Range,
        else_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_casgn(
        scope: *mut Node,
        name: BytePtr,
        value: *mut Node,
        double_colon_l: *mut Range,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_cbase(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_class(
        name: *mut Node,
        superclass: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        operator_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_complex(
        value: BytePtr,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_const_(
        scope: *mut Node,
        name: BytePtr,
        double_colon_l: *mut Range,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_const_pattern(
        const_: *mut Node,
        pattern: *mut Node,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_csend(
        recv: *mut Node,
        method_name: BytePtr,
        args: NodeVec,
        dot_l: *mut Range,
        selector_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_cvar(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_cvasgn(
        name: BytePtr,
        value: *mut Node,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_def(
        name: BytePtr,
        args: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        name_l: *mut Range,
        end_l: *mut Range,
        assignment_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_defined(
        value: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_defs(
        definee: *mut Node,
        name: BytePtr,
        args: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        operator_l: *mut Range,
        name_l: *mut Range,
        assignment_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_dstr(
        parts: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_dsym(
        parts: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_eflipflop(
        left: *mut Node,
        right: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_empty_else(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_encoding_(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_ensure(
        body: *mut Node,
        ensure: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_erange(
        left: *mut Node,
        right: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_false_(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_file(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_find_pattern(
        elements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_float(
        value: BytePtr,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_for_(
        iterator: *mut Node,
        iteratee: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        operator_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_forward_arg(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_forwarded_args(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_gvar(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_gvasgn(
        name: BytePtr,
        value: *mut Node,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_hash(
        pairs: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_kwargs(pairs: NodeVec, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_hash_pattern(
        elements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_heredoc(
        parts: NodeVec,
        heredoc_body_l: *mut Range,
        heredoc_end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_if_(
        cond: *mut Node,
        if_true: *mut Node,
        if_false: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        else_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_if_guard(
        cond: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_if_mod(
        cond: *mut Node,
        if_true: *mut Node,
        if_false: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_if_ternary(
        cond: *mut Node,
        if_true: *mut Node,
        if_false: *mut Node,
        question_l: *mut Range,
        colon_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_iflipflop(
        left: *mut Node,
        right: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_pattern(
        value: *mut Node,
        pattern: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_pattern_p(
        value: *mut Node,
        pattern: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_in_pattern(
        pattern: *mut Node,
        guard: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_index(
        recv: *mut Node,
        indexes: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_index_asgn(
        recv: *mut Node,
        indexes: NodeVec,
        value: *mut Node,
        begin_l: *mut Range,
        end_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_int(value: BytePtr, operator_l: *mut Range, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_irange(
        left: *mut Node,
        right: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_ivar(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_ivasgn(
        name: BytePtr,
        value: *mut Node,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_kwarg(name: BytePtr, name_l: *mut Range, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_kwbegin(
        statements: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_kwnilarg(name_l: *mut Range, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_kwoptarg(
        name: BytePtr,
        default_: *mut Node,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_kwrestarg(
        name: BytePtr,
        operator_l: *mut Range,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_kwsplat(
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_lambda(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_line(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_lvar(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_lvasgn(
        name: BytePtr,
        value: *mut Node,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_masgn(
        lhs: *mut Node,
        rhs: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_alt(
        lhs: *mut Node,
        rhs: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_as(
        value: *mut Node,
        as_: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_current_line(re: *mut Node, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_match_nil_pattern(
        operator_l: *mut Range,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_rest(
        name: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_match_var(name: BytePtr, name_l: *mut Range, expression_l: *mut Range)
        -> *mut Node;
}
extern "C" {
    pub fn make_match_with_lvasgn(
        re: *mut Node,
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_mlhs(
        items: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_module(
        name: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_next(args: NodeVec, keyword_l: *mut Range, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_nil(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_nth_ref(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_numblock(
        call: *mut Node,
        numargs: u32,
        body: *mut Node,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_op_asgn(
        recv: *mut Node,
        operator_: BytePtr,
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_optarg(
        name: BytePtr,
        default_: *mut Node,
        name_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_or(
        lhs: *mut Node,
        rhs: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_or_asgn(
        recv: *mut Node,
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_pair(
        key: *mut Node,
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_pin(var: *mut Node, selector_l: *mut Range, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_postexe(
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_preexe(
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_procarg0(
        args: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_rational(
        value: BytePtr,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_redo(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_reg_opt(options: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_regexp(
        parts: NodeVec,
        options: *mut Node,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_rescue(
        body: *mut Node,
        rescue_bodies: NodeVec,
        else_: *mut Node,
        else_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_rescue_body(
        exc_list: *mut Node,
        exc_var: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        assoc_l: *mut Range,
        begin_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_restarg(
        name: BytePtr,
        operator_l: *mut Range,
        name_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_retry(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_return_(
        args: NodeVec,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_sclass(
        expr: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        operator_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_self_(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_send(
        recv: *mut Node,
        method_name: BytePtr,
        args: NodeVec,
        dot_l: *mut Range,
        selector_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_shadowarg(name: BytePtr, expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_splat(
        value: *mut Node,
        operator_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_str_(
        value: BytePtr,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_super_(
        args: NodeVec,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_sym(
        name: BytePtr,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_true_(expression_l: *mut Range) -> *mut Node;
}
extern "C" {
    pub fn make_undef(names: NodeVec, keyword_l: *mut Range, expression_l: *mut Range)
        -> *mut Node;
}
extern "C" {
    pub fn make_unless_guard(
        cond: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_until(
        cond: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_until_post(
        cond: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_when(
        patterns: NodeVec,
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_while_(
        cond: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_while_post(
        cond: *mut Node,
        body: *mut Node,
        keyword_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_x_heredoc(
        parts: NodeVec,
        heredoc_body_l: *mut Range,
        heredoc_end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_xstr(
        parts: NodeVec,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_yield_(
        args: NodeVec,
        keyword_l: *mut Range,
        begin_l: *mut Range,
        end_l: *mut Range,
        expression_l: *mut Range,
    ) -> *mut Node;
}
extern "C" {
    pub fn make_zsuper(expression_l: *mut Range) -> *mut Node;
}
#[repr(i32)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum CommentType {
    INLINE = 0,
    DOCUMENT = 1,
    UNKNOWN = 2,
}
#[repr(i32)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum ErrorLevel {
    WARNING = 0,
    ERROR = 1,
}
#[repr(i32)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum MagicCommentKind {
    ENCODING = 0,
    FROZEN_STRING_LITERAL = 1,
    WARN_INDENT = 2,
    SHAREABLE_CONSTANT_VALUE = 3,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Loc {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Token {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Comment {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct Diagnostic {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct CustomDecoder {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct MagicComment {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct TokenRewriter {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct ParserResult {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct ParserOptions {
    _unused: [u8; 0],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct TokenVec {
    pub ptr: *mut *mut Token,
    pub length: u32,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct DiagnosticVec {
    pub ptr: *mut *mut Diagnostic,
    pub length: u32,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct CommentVec {
    pub ptr: *mut *mut Comment,
    pub length: u32,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct MagicCommentVec {
    pub ptr: *mut *mut MagicComment,
    pub length: u32,
}
extern "C" {
    pub fn make_parser_result(
        ast: *mut Node,
        tokens: TokenVec,
        diagnostics: DiagnosticVec,
        comments: CommentVec,
        magic_comments: MagicCommentVec,
        input: BytePtr,
    ) -> *mut ParserResult;
}
extern "C" {
    pub fn make_comment(kind: CommentType, location: *mut Range) -> *mut Comment;
}
extern "C" {
    pub fn make_diagnostic(
        level: ErrorLevel,
        message: BytePtr,
        range: *mut Range,
    ) -> *mut Diagnostic;
}
extern "C" {
    pub fn make_magic_comment(
        kind: MagicCommentKind,
        key_l: *mut Range,
        value_l: *mut Range,
    ) -> *mut MagicComment;
}
extern "C" {
    pub fn make_range(begin_pos: u32, end_pos: u32) -> *mut Range;
}
extern "C" {
    pub fn make_loc(begin: u32, end: u32) -> *mut Loc;
}
extern "C" {
    pub fn make_token(
        token_type: ::std::os::raw::c_int,
        token_value: BytePtr,
        loc: *mut Loc,
    ) -> *mut Token;
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct CustomDecoderResult {
    pub success: bool,
    pub output: BytePtr,
    pub error_message: BytePtr,
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser9low_level14custom_decoder19CustomDecoderResult2OkENS_7BytePtrE"]
    pub fn CustomDecoderResult_Ok(output: BytePtr) -> CustomDecoderResult;
}
extern "C" {
    #[link_name = "\u{1}__ZN15lib_ruby_parser9low_level14custom_decoder19CustomDecoderResult5ErrorENS_7BytePtrE"]
    pub fn CustomDecoderResult_Error(error_message: BytePtr) -> CustomDecoderResult;
}
impl CustomDecoderResult {
    #[inline]
    pub unsafe fn Ok(output: BytePtr) -> CustomDecoderResult {
        CustomDecoderResult_Ok(output)
    }
    #[inline]
    pub unsafe fn Error(error_message: BytePtr) -> CustomDecoderResult {
        CustomDecoderResult_Error(error_message)
    }
}
extern "C" {
    pub fn rewrite(
        decoder: *mut CustomDecoder,
        encoding: BytePtr,
        input: BytePtr,
    ) -> CustomDecoderResult;
}
extern "C" {
    pub fn parser_options_buffer_name(options: *mut ParserOptions) -> BytePtr;
}
extern "C" {
    pub fn parser_options_custom_decoder(options: *mut ParserOptions) -> *mut CustomDecoder;
}
extern "C" {
    pub fn parser_options_token_rewriter(options: *mut ParserOptions) -> *mut TokenRewriter;
}
extern "C" {
    pub fn parser_options_debug(options: *mut ParserOptions) -> bool;
}
extern "C" {
    pub fn parser_options_record_tokens(options: *mut ParserOptions) -> bool;
}
extern "C" {
    pub fn free_str(s: *mut ::std::os::raw::c_char);
}
#[repr(u32)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum RawRewriteAction {
    REWRITE_ACTION_KEEP = 0,
    REWRITE_ACTION_DROP = 1,
}
#[repr(u32)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum RawLexStateAction {
    LEX_STATE_SET = 0,
    LEX_STATE_KEEP = 1,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct RawToken {
    pub token_type: ::std::os::raw::c_int,
    pub token_value: BytePtr,
    pub loc_begin: u32,
    pub loc_end: u32,
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct RawTokenRewriterResult {
    pub rewrite_action: RawRewriteAction,
    pub lex_state_action: RawLexStateAction,
    pub next_state: ::std::os::raw::c_int,
    pub token: RawToken,
}
extern "C" {
    pub fn rewrite_token(
        rewriter: *mut TokenRewriter,
        token: RawToken,
        input: BytePtr,
    ) -> RawTokenRewriterResult;
}
extern "C" {
    pub fn token_name(id: ::std::os::raw::c_int) -> BytePtr;
}
