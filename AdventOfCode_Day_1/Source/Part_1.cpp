#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#include "../Headers/Part_1.h"

size_t ResultPartOne()
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

    for (size_t i = 0; i < leftList.size() - 1; i++)
    {
        bool swappedItem = false;
        for (size_t j = 0; j < leftList.size() - i - 1; j++)
        {
            size_t a = leftList[j];
            size_t b = leftList[j + 1];

            if (a <= b) continue;
            leftList[j] = b;
            leftList[j + 1] = a;
            swappedItem = true;
        }

        if (!swappedItem) break;
    }

    for (size_t i = 0; i < rightList.size() - 1; i++)
    {
        bool swappedItem = false;
        for (size_t j = 0; j < rightList.size() - i - 1; j++)
        {
            size_t a = rightList[j];
            size_t b = rightList[j + 1];

            if (a <= b) continue;
            rightList[j] = b;
            rightList[j + 1] = a;
            swappedItem = true;
        }

        if (!swappedItem) break;
    }

    size_t total = 0;
    for (size_t i = 0; i < leftList.size(); i++) {
        size_t a = leftList[i];
        size_t b = rightList[i];

        if (a < b) {
            a = rightList[i];
            b = leftList[i];
        }

        size_t result = a - b;
        total += result;
    }

    return total;
}