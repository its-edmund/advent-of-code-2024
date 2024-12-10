#include "day02.h"

#include <vector>
#include <map>
#include <fstream>
#include <cmath>

#include "advent/advent_utils.h"

namespace {
    int64_t solve_p1(std::istream& input) {
        int result = 0;

        std::istringstream iss;
        std::string line;

        while (std::getline(input, line)) {
            int num1 = 0;
            iss.str(line);

            std::vector<int> nums;
            bool safe = true;
            bool increasing = false;
            int curr = -1;

            while (iss >> num1) {
                nums.push_back(num1);
            }

            for (int i = 1; i < nums.size(); i++) {
                if (i == 1) {
                    increasing = (nums[1] - nums[0]) > 0;
                }
                if (!((increasing && nums[i] - nums[i - 1] > 0 && nums[i] - nums[i - 1] < 4) || (!increasing && nums[i] - nums[i - 1] < 0 && nums[i] - nums[i - 1] > -4))) {
                    safe = false;
                    break;
                }
            }
            
            if (safe) {
                result++;
                std::cout << "[SAFE] ";
                for (auto i : nums) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "[UNSAFE] ";
                for (auto i : nums) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }

            iss.clear();
        }

        return result;
    }

    bool safe_check(int num_1, int num_2, bool increasing) {
        if (increasing) {
            return num_2 - num_1 > 0 && num_2 - num_1 < 4;
        } else {
            return num_2 - num_1 < 0 && num_2 - num_1 > -4;
        }
    }

    int64_t solve_p2(std::istream& input) {
        int result = 0;

        std::istringstream iss;
        std::string line;

        while (std::getline(input, line)) {
            int num = 0;
            iss.str(line);

            std::vector<int> nums;
            int curr = -1;
            int total = 0;

            std::cout << line << std::endl;

            while (iss >> num) {
                nums.push_back(num);
                if (curr != -1) {
                    total += (num - curr) > 0 ? 1 : -1;
                }
                curr = num;
            }

            bool increasing = total > 0;

            for (int i = 0; i < nums.size(); i++) {
                std::vector<int> nums_copy = nums;
                nums_copy.erase(nums_copy.begin() + i);
                bool safe = true;

                for (int j = 1; j < nums_copy.size(); j++) {
                    if (!safe_check(nums_copy[j - 1], nums_copy[j], increasing)) {
                        safe = false;
                        break;
                    }
                }

                bool dampened = false;

                if (safe) {
                    result++;
                    break;
                }
            }

            iss.clear();
        }

        return result;
    }
}

Advent::ResultType day02_part1() {
    std::ifstream input = open_puzzle_input(2);
    return solve_p1(input);
}

Advent::ResultType day02_part2() {
    std::ifstream input = open_puzzle_input(2);
    return solve_p2(input);
}

Advent::ResultType day02_part1_example() {
    std::ifstream input = open_example_input(2);
    return solve_p1(input);
}

Advent::ResultType day02_part2_example() {
    std::ifstream input = open_example_input(2);
    return solve_p2(input);
}
