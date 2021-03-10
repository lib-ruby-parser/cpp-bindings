LIB_RUBY_PARSER_TMP_H=target/lib-ruby-parser-tmp.h
LIB_RUBY_PARSER_H=target/lib-ruby-parser.h

cat src/byte_ptr.h > $LIB_RUBY_PARSER_TMP_H
cat src/comment_type.h >> $LIB_RUBY_PARSER_TMP_H
cat src/error_level.h >> $LIB_RUBY_PARSER_TMP_H
cat src/magic_comment_kind.h >> $LIB_RUBY_PARSER_TMP_H

cat src/bytes.h >> $LIB_RUBY_PARSER_TMP_H
cat src/input.h >> $LIB_RUBY_PARSER_TMP_H
cat src/loc.h >> $LIB_RUBY_PARSER_TMP_H
cat src/token.h >> $LIB_RUBY_PARSER_TMP_H

cat src/gen/messages/classes.h >> $LIB_RUBY_PARSER_TMP_H
cat src/gen/messages/variant.h >> $LIB_RUBY_PARSER_TMP_H
cat src/message.h >> $LIB_RUBY_PARSER_TMP_H

cat src/gen/nodes/classes.h >> $LIB_RUBY_PARSER_TMP_H
cat src/gen/nodes/variant.h >> $LIB_RUBY_PARSER_TMP_H
cat src/node.h >> $LIB_RUBY_PARSER_TMP_H

cat src/comment.h >> $LIB_RUBY_PARSER_TMP_H
cat src/custom_decoder.h >> $LIB_RUBY_PARSER_TMP_H
cat src/diagnostic.h >> $LIB_RUBY_PARSER_TMP_H
cat src/helpers.h >> $LIB_RUBY_PARSER_TMP_H
cat src/magic_comment.h >> $LIB_RUBY_PARSER_TMP_H
cat src/token_rewriter.h >> $LIB_RUBY_PARSER_TMP_H

cat src/parser_options.h >> $LIB_RUBY_PARSER_TMP_H
cat src/parser_result.h >> $LIB_RUBY_PARSER_TMP_H

echo "#ifndef LIB_RUBY_PARSER_H" > $LIB_RUBY_PARSER_H
echo "#define LIB_RUBY_PARSER_H" >> $LIB_RUBY_PARSER_H

cat $LIB_RUBY_PARSER_TMP_H | \
    grep -v "#include \"" | \
    grep -v "#ifndef LIB_RUBY_PARSER_" | \
    grep -v "#define LIB_RUBY_PARSER_" | \
    grep -v "#endif // LIB_RUBY_PARSER_" \
    >> $LIB_RUBY_PARSER_H
echo "#endif // LIB_RUBY_PARSER_H" >> $LIB_RUBY_PARSER_H

rm -f $LIB_RUBY_PARSER_TMP_H
