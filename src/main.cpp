#include "advent/advent_of_code.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No mode provided. Usage: ./program <mode>\n";
        return 1;
    }

    std::string mode = argv[1];
    if (mode == "solve") {
        Advent::run_tests();
    } else if (mode == "test") {
        Advent::verify_examples();
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }
}

