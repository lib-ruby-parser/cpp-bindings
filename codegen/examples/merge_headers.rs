const HEADERS: &[&str] = &[
    "shared_byte_list.hpp",
    "string.hpp",
    "bytes.hpp",
    "source_line.hpp",
    "decoded_input.hpp",
    "loc.hpp",
    "token_ids.hpp",
    "token.hpp",
    "comment.hpp",
    "magic_comment.hpp",
    "nodes.hpp",
    "messages.hpp",
    "diagnostic.hpp",
    "decoder.hpp",
    "token_rewriter.hpp",
    "parser_options.hpp",
    "parser_result.hpp",
    "api.hpp",
];

fn process_header(header_path: &str, sys_includes: &mut Vec<String>, contents: &mut Vec<String>) {
    println!("Processing {:?}", header_path);

    let header = std::fs::read_to_string(header_path).expect("failed to read header file");
    let mut in_test_section = false;

    let lines = header.lines().collect::<Vec<_>>();

    for (line_idx, line) in lines.iter().cloned().enumerate() {
        let last_line = line_idx
            .checked_sub(1)
            .and_then(|idx| lines.get(idx).map(|l| l.to_string()))
            .unwrap_or_default();

        if line == "#endif" && in_test_section {
            in_test_section = false;
            continue;
        }

        if in_test_section {
            continue;
        }
        if line == "#ifdef TEST_ENV" {
            if in_test_section {
                panic!("nested TEST_ENV sections are not supported");
            }
            in_test_section = true;
            continue;
        }

        if line == "namespace lib_ruby_parser" {
            continue;
        }

        if last_line == "namespace lib_ruby_parser" && line == "{" {
            continue;
        }

        if line == "} // namespace lib_ruby_parser" {
            continue;
        }

        if line.starts_with("// This file is autogenerated by ") {
            continue;
        }

        if line.starts_with("#include <") {
            // sys include
            sys_includes.push(line.to_string());
            continue;
        }
        if line.starts_with("#include \"") {
            // local include, skip
            continue;
        }
        if line.starts_with("#ifndef LIB_RUBY_PARSER_")
            || (line.starts_with("#define LIB_RUBY_PARSER_") && line.ends_with("_HPP"))
            || line.starts_with("#endif // LIB_RUBY_PARSER_")
        {
            // header guard, skip
            continue;
        }

        if line.is_empty() {
            if let Some(last_pushed_line) = contents.last() {
                if last_pushed_line.is_empty() {
                    // drop 2 consecutive empty lines
                    continue;
                }
            }
        }
        contents.push(line.to_string())
    }
}

fn main() {
    let mut sys_includes = vec![];
    let mut contents = vec![];

    for header in HEADERS {
        process_header(*header, &mut sys_includes, &mut contents);
    }

    sys_includes.sort();
    sys_includes.dedup();

    let contents = format!(
        "#ifndef LIB_RUBY_PARSER_HPP
#define LIB_RUBY_PARSER_HPP

{sys_includes}

namespace lib_ruby_parser
{{
{contents}
}} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HPP
",
        sys_includes = sys_includes.join("\n"),
        contents = contents.join("\n")
    );

    std::fs::write("lib-ruby-parser.hpp", contents).unwrap();
}
