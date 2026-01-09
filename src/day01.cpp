
#include "day01.h"

#include <iostream>
#include <fstream>
#include <exception>

int main() {
    std::cout << "--- Day 01 ---" << std::endl;

    std::cout << "- Part 1 -" << std::endl;
    Day01::part1();

    std::cout << "- Part 2 -" << std::endl;
    Day01::part2();

    return 0;
}

void Day01::part1() {
    std::ifstream input("./inputs/day01.txt");
    std::string line;

    uint zeroCount = 0;
    int dial = 50;

    while (getline(input, line))
    {
        // std::cout << line << std::endl;

        uint turn = std::stoi(line.substr(1));

        switch (line[0])
        {
        case 'L':
            dial -= turn;
            break;
        case 'R':
            dial += turn;
            break;
        default:
            throw std::invalid_argument("Input invalid");
            break;
        }

        if (dial < 0)
        {
            dial = 100 + dial; // dial value is negative so add it.
        }
        dial %= 100; // if dial is > 99 wrap the other way

        if (dial == 0)
        {
            zeroCount++;
            // std::cout << "new zero!" << std::endl;
        }

        // std::cout << dial << std::endl;
    }

    std::cout << zeroCount << std::endl;
}

void Day01::part2() {
    std::ifstream input("./inputs/day01.txt");
    std::string line;

    uint zeroCount = 0;
    int dial = 50;
    int oldDial = 0;

    while (getline(input, line))
    {
        // std::cout << line << std::endl;

        uint turn = std::stoi(line.substr(1));

        uint loops = turn / 100;
        zeroCount += loops;
        turn %= 100;

        oldDial = dial;
        bool isRight = line[0] == 'R';
        dial += isRight ? turn : -turn;

        if (dial < 0)
        {
            dial = 100 + dial; // dial value is negative so add it.
        } else if (dial > 99) {
            dial %= 100;
        }
        dial %= 100; // if dial is > 99 wrap the other way

        // std::cout << oldDial << " -> " << dial << std::endl;

        if (dial == 0)
        {
            zeroCount++;
            // std::cout << "new zero!" << std::endl;
        } else if (dial!= 0 && oldDial != 0) {
            if (isRight && dial < oldDial) {
                zeroCount++;
                // std::cout << "new zero!" << std::endl;
            }
            if (!isRight && dial > oldDial) {
                zeroCount++;
                // std::cout << "new zero!" << std::endl;
            }
        }

        // std::cout << dial << std::endl;
    }

    std::cout << zeroCount << std::endl;
}