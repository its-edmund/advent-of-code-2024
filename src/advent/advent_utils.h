#pragma once

#include <format>
#include <fstream>
#include <iostream>
#include <filesystem>

struct ResultStringifier {
    std::string operator()(const std::string& in) const noexcept { return in; }
    template <typename T>
    std::string operator()(T in) const { return std::to_string(in); }
};

static std::string to_string(const Advent::ResultType& rt) {
    return std::visit(ResultStringifier{}, rt);
}

static std::ifstream open_input(const std::string& filename) {
    auto result = std::ifstream{ filename };
    // AdventCheck(result.is_open());
    if (std::filesystem::file_size(filename) <= 0) {
        std::cerr << "\nWARNING! File '" << filename << "' is empty.";
    }
    return result;
}

static std::ifstream open_example_input(int day) {
    std::string file_name = std::format("src/day{:02}/day{:02}_example.txt", day, day);
    return open_input(file_name);
}

static std::ifstream open_puzzle_input(int day) {
    std::string file_name = std::format("src/day{:02}/day{:02}.txt", day, day);
    return open_input(file_name);
}
