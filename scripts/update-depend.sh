#!/usr/bin/env bash

set -eu

echo '' > .depend

for filename in *.cpp; do
    [ -e "$filename" ] || continue
    objfile="${filename%.cpp}.o"

    $CC -MT $objfile -MM $filename >> .depend
    echo "" >> .depend
done

$CC -MT "tests/runner" -MM "tests/runner.cpp" >> .depend
echo "" >> .depend

$CC -MT "benchmark/cpp-parser" -MM "benchmark/benchmark.cpp" >> .depend
echo "" >> .depend

sed 's/tests\/\.\.\///g' .depend > .depend-tmp
mv .depend-tmp .depend

sed 's/benchmark\/\.\.\///g' .depend > .depend-tmp
mv .depend-tmp .depend
