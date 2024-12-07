#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to parse the input file
vector<string> parseInput(const string& filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return lines;
    }

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

// Function to solve part 1
int solvePart1(const vector<string>& input) {
    int result = 0;

    int num1 = 0, num2 = 0;
    std::istringstream iss;
    vector<int> list1;
    vector<int> list2;

    for (const string& line : input) {
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

// Function to solve part 2
int solvePart2(const vector<string>& input) {
    int result = 0;

    int num1 = 0, num2 = 0;
    std::istringstream iss;
    vector<int> list1;
    map<int, int> map2;

    // Logic for part 2 goes here
    for (const string& line : input) {
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    vector<string> input = parseInput(inputFile);

    if (input.empty()) {
        cerr << "Error: Input file is empty or not readable" << endl;
        return 1;
    }

    cout << "Part 1: " << solvePart1(input) << endl;
    cout << "Part 2: " << solvePart2(input) << endl;

    return 0;
}

