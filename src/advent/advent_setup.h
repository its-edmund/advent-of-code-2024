#pragma once

#include "day01/day01.h"
#include "day02/day02.h"

Advent::VerificationTest make_test(std::string name, Advent::TestFunc test_func, std::string expected_result);

#define TESTCASE(func_name, expected_result) make_test(std::string{ #func_name }, func_name, expected_result)

static const std::array<Advent::VerificationTest, 4> tests = {
    TESTCASE(day01_part1, "11"),
    TESTCASE(day01_part2, "31"),
    TESTCASE(day02_part1, "11"),
    TESTCASE(day02_part2, "11")
};
