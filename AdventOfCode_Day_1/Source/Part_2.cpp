#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../Headers/Part_2.h"

size_t ResultPartTwo()
{
    std::vector<size_t> leftList;
    std::vector<size_t> rightList;
    std::ifstream file("E:/Documents/Projects/AdventOfCode/x64/Debug/input_day_1.txt");

    std::string line;
    while (std::getline(file, line)) {
        // Split on string
        std::string delimiter = "   ";

        int index = line.find(delimiter);
        std::string left = line.substr(0, index);
        std::string right = line.substr(index + delimiter.length());

        // Add to vector and convert to number
        leftList.push_back(std::stoi(left));
        rightList.push_back(std::stoi(right));
    }

    size_t total = 0;
    for (size_t i = 0; i < leftList.size(); i++) {
        size_t a = leftList[i];
        size_t count = 0;

        for (size_t j = 0; j < rightList.size(); j++) {
            size_t b = rightList[j];

            if (a != b) continue;
            count++;
        }

        total += a * count;
    }

    return total;
}