#pragma once

#include "day01/day01.h"
#include "day02/day02.h"

Advent::VerificationTest make_test(std::string name, Advent::TestFunc test_func, std::string expected_result);
Advent::VerificationTest make_test(std::string name, Advent::TestFunc test_func);

// Helper macros for dispatching
#define GET_MACRO(_1, _2, NAME, ...) NAME
#define TESTCASE(...) GET_MACRO(__VA_ARGS__, TESTCASE2, TESTCASE1)(__VA_ARGS__)

// Implementations
#define TESTCASE1(func_name) make_test(std::string{#func_name}, func_name)
#define TESTCASE2(func_name, expected_result) make_test(std::string{#func_name}, func_name, expected_result)

static const std::array<Advent::VerificationTest, 4> examples = {
    TESTCASE(day01_part1_example, "11"),
    TESTCASE(day01_part2_example, "31"),
    TESTCASE(day02_part1_example, "2"),
    TESTCASE(day02_part2_example, "4")
};

static const std::array<Advent::VerificationTest, 4> tests = {
    TESTCASE(day01_part1),
    TESTCASE(day01_part2),
    TESTCASE(day02_part1),
    TESTCASE(day02_part2)
};
