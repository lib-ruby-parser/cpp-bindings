mod fns;
mod fns_c;
mod fns_shared;

mod messages_cpp;
mod messages_hpp;

mod nodes_cpp;
mod nodes_hpp;

mod message_rs;
mod node_rs;

pub(crate) fn codegen() {
    messages_hpp::codegen();
    messages_cpp::codegen();

    nodes_hpp::codegen();
    nodes_cpp::codegen();

    node_rs::codegen();
    message_rs::codegen();
}
