#pragma once

#include <string>
#include <functional>

namespace Advent {

using ResultType = std::variant<std::string, int64_t, uint64_t>;
using TestFunc = std::function<ResultType()>;

struct Test {
    TestFunc func;
    ResultType execute() { return func(); }
	explicit Test(TestFunc func_) : func{func_} {};
};

struct VerificationTest {
    std::string name;
    Test test_func;
	std::optional<std::string> expected_result;
    VerificationTest(std::string name_, TestFunc func) : name(std::move(name_)), test_func(func) {};
};

enum class TestStatus : char {
    UNKNOWN,
    PASS,
    FAILED,
    FILTERED
};

struct TestResult
{
	std::string name;
	std::string result;
	std::string expected;
	TestStatus status = TestStatus::UNKNOWN;
	std::chrono::nanoseconds time_taken;
};

};

