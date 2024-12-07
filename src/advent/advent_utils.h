#pragma once

#include <format>

inline std::ifstream open_input(const std::string& filename)
	{
		auto result = std::ifstream{ filename };
		AdventCheck(result.is_open());
		if (std::filesystem::file_size(filename) <= 0)
		{
			std::cerr << "\nWARNING! File '" << filename << "' is empty.";
		}
		return result;
	}

inline std::ifstream open_puzzle_input(int day) {
    const std::string name = std::format("day{:02}/advent{:02}.txt", day);

}
