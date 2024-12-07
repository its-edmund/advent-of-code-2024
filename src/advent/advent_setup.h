#pragma once

#include "advent_types.h"

VerificationTest make_test(std::string name, TestFunc test_func, std::optional<std::string> expected_result);

static const VerificationTests tests[] = {

}
