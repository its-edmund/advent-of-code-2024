#include "day01.h"

#include <vector>
#include <map>
#include <fstream>

#include "advent/advent_utils.h"

namespace {
    int64_t solve_p1(std::istream& input) {
        int result = 0;

        int num1 = 0, num2 = 0;
        std::istringstream iss;
        std::vector<int> list1;
        std::vector<int> list2;
        std::string line;

        while (std::getline(input, line)) {
            iss.str(line);

            if (iss >> num1 >> num2) {
                list1.push_back(num1);
                list2.push_back(num2);
            }

            iss.clear();
        }

        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());

        for (int i = 0; i < list1.size(); i++) {
            result += abs(list1[i] - list2[i]);
        }

        return result;
    }

    int64_t solve_p2(std::istream& input) {
        int result = 0;

        int num1 = 0, num2 = 0;
        std::istringstream iss;
        std::vector<int> list1;
        std::map<int, int> map2;
        std::string line;

        // Logic for part 2 goes here
        while (std::getline(input, line)) {
            iss.str(line);

            if (iss >> num1 >> num2) {
                list1.push_back(num1);
                map2[num2]++;
            }

            iss.clear();
        }

        for (int i : list1) {
            result += i * map2[i];
        }

        return result;
    }
}

Advent::ResultType day01_part1() {
    std::ifstream input = open_puzzle_input(1);
    return solve_p1(input);
}

Advent::ResultType day01_part2() {
    std::ifstream input = open_puzzle_input(1);
    return solve_p2(input);
}

Advent::ResultType day01_part1_example() {
    std::ifstream input = open_example_input(1);
    return solve_p1(input);
}

Advent::ResultType day01_part2_example() {
    std::ifstream input = open_example_input(1);
    return solve_p2(input);
}
