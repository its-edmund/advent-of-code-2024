#include "advent_of_code.h"

#include <iostream>
#include <chrono>

#include "advent_types.h"
#include "advent_utils.h"
#include "advent_setup.h"

Advent::VerificationTest make_test(std::string name, Advent::TestFunc test_func, std::string expected_result) {
    return Advent::VerificationTest{ std::move(name), test_func, std::move(expected_result)};
}

Advent::VerificationTest make_test(std::string name, Advent::TestFunc test_func) {
    return Advent::VerificationTest{ std::move(name), test_func};
}

namespace Advent {

ResultType run_test_func(Test test_func) {
    return test_func.execute();
}

TestResult run_test(const Advent::VerificationTest& test) {
    std::cout << "Running test " << test.name << "..." << std::endl;
    const ResultType res = run_test_func(test.test_func);
    const std::string string_result = to_string(res);
    std::cout << "\nFinished " << test.name << ": got " << string_result << '\n';

    if (test.expected_result.has_value()) {
        if (string_result == test.expected_result.value()) {          
            return Advent::TestResult{test.name, string_result, test.expected_result.value(), Advent::TestStatus::PASSED, std::chrono::nanoseconds{ 0 }};
        } else {
            return Advent::TestResult{test.name, string_result, test.expected_result.value(), Advent::TestStatus::FAILED, std::chrono::nanoseconds{ 0 }};
        }
    } else {
        return Advent::TestResult{test.name, string_result, "", Advent::TestStatus::UNKNOWN, std::chrono::nanoseconds{ 0 }};
    }
}

void verify_examples() {
    std::cout << "Running tests..." << std::endl;

    constexpr auto NUM_TESTS = std::size(examples);
    std::array<Advent::TestResult, NUM_TESTS> results;

    std::transform(examples.begin(), examples.end(), results.begin(), [](const Advent::VerificationTest& test) {
        return run_test(test);
    });

    auto result_to_string = [](const TestResult& result) {
		std::ostringstream oss;
		oss << result.name << ": " << result.result << " - ";
		switch (result.status)
		{
		case TestStatus::PASSED:
			oss << "PASS\n";
			break;
		case TestStatus::FAILED:
			oss << "FAIL (expected " << result.expected << ")\n";
			break;
		case TestStatus::FILTERED:
			return std::string{ "" };
		default: // unknown
			oss << "[Unknown]\n";
			break;
		}
		return oss.str();
	};

    for (size_t i = 0; i < NUM_TESTS; i++) {
        std::cout << result_to_string(results[i]) << std::endl;
    }

    return;
}

void run_tests() {
    std::cout << "Running examples..." << std::endl;

    constexpr auto NUM_TESTS = std::size(tests);
    std::array<Advent::TestResult, NUM_TESTS> results;

    std::transform(tests.begin(), tests.end(), results.begin(), [](const Advent::VerificationTest& test) {
        return run_test(test);
    });

    auto result_to_string = [](const TestResult& result) {
		std::ostringstream oss;
		oss << result.name << ": " << result.result << " - ";
		switch (result.status)
		{
		case TestStatus::PASSED:
			oss << "PASS\n";
			break;
		case TestStatus::FAILED:
			oss << "FAIL (expected " << result.expected << ")\n";
			break;
		case TestStatus::FILTERED:
			return std::string{ "" };
		default: // unknown
			oss << "[Unknown]\n";
			break;
		}
		return oss.str();
	};

    for (size_t i = 0; i < NUM_TESTS; i++) {
        std::cout << result_to_string(results[i]) << std::endl;
    }

    return;
}
}
