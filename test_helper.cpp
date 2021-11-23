#include "test_helper.hpp"
#include <cstring>
#include <iostream>
#include "string.h"

void run_tests_as_group(const char *group_name, const test_fn_t *tests, size_t count)
{
    std::cerr << "Running group \"" << group_name << "\" with " << count << " tests:\n";
    for (size_t i = 0; i < count; i++)
    {
        test_fn_t test_fn = tests[i];
        std::cerr << "  - ";
        test_fn();
        std::cerr << "\n";
    }
}
