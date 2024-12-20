#include "../Headers/Part_1.h"

size_t ResultPartOne() {
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

    // Go through each report checking every level
    size_t correct = 0;
    for (size_t i = 0; i < reports.size(); i++) {
        std::vector<size_t> report = reports[i];

        bool isCorrect = true;
        bool isPositive = report[0] < report[1];
        for (size_t j = 0; j < report.size() - 1; j++) {
            size_t a = report[j];
            size_t b = report[j + 1];
            size_t diff = isPositive ? b - a : a - b;

            if (diff >= 1 && diff <= 3) continue;
            isCorrect = false;
            break;
        }

        if (isCorrect) correct++;
    }

    return correct;
}