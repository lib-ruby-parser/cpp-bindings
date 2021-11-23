#!/usr/bin/env bash

set -eu

echo '' > .depend

for filename in *.cpp; do
    [ -e "$filename" ] || continue
    objfile="${filename%.cpp}.o"

    $CC -DTEST_ENV -MT $objfile -MM $filename >> .depend
    echo "" >> .depend
done

$CC -MT "tests/runner" -MM "tests/test.cpp" >> .depend
echo "" >> .depend

# $CC -MT "benchmark/c-parser" -MM "benchmark/benchmark.cpp" >> .depend
# echo "" >> .depend
