extern crate lib_ruby_parser;

fn main() {
    let result = lib_ruby_parser::Parser::new(
        b"2 + 2",
        lib_ruby_parser::ParserOptions {
            record_tokens: true,
            ..Default::default()
        },
    )
    .do_parse();

    println!("{:#?}", result)
}
