#include "../Headers/Part_2.h"

bool isValid(int a, int b, bool isPositive) {
    int diff = isPositive ? b - a : a - b ;
    return diff >= 1 && diff <= 3;
}

size_t ResultPartTwo() {
    std::ifstream file("E:/Documents/Projects/AdventOfCode/x64/Debug/input_day_2.txt");

    std::string line;
    std::string element;

    std::vector<std::vector<size_t>> reports;

    // Split on space
    char delimiter = ' ';
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::vector<size_t> report;
        while (std::getline(ss, element, delimiter)) {
            report.push_back(std::stoi(element));
        }
        reports.push_back(report);
    }

    // Go through each report checking every level also checking the next level for the "Problem Dampener"
    // size_t is fucking unsigned....

    size_t correct = 0;
    for (size_t i = 0; i < reports.size(); i++) {
        std::vector<size_t> report = reports[i];

        bool isCorrect = true;
        bool removedLevel = false;

        bool isPositive = false; // Needs rework since the first or second could be removed
        size_t a = report[0];
        size_t b = report[1];
        size_t c = report[2];
        isPositive = b > a || c > b || c > a;

        for (size_t j = 0; j < report.size() - 2; j++) {
            size_t a = report[j];
            size_t b = report[j + 1];
            size_t c = report[j + 2];

            if (isValid(a, b, isPositive)) continue;
            if (!removedLevel && (isValid(a,c, isPositive) || isValid(b,c, isPositive))) {
                removedLevel = true;
                j++;
                continue;
            }

            isCorrect = false;
            break;
        }

        if (isCorrect) correct++;
    }

    return correct; // Needs to be fixed.... Too tired to get it right
}