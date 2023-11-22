//
// Created by Oliver Walton on 01/11/2023.
//

#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class FileHandler {
public:
    explicit FileHandler(const std::string& filename)
    {
        filename_ = filename;
    }

    void Process() {
        std::fstream inputFileStream(filename_);
        if (!inputFileStream.good()) {
            std::cout << "Error opening input file, check file exits in correct directory." << std::endl;
        }

        if (inputFileStream.eof()) {

        } else {
            int shiftRegisters;
            int* startingStates;

            std::ifstream inputFileStream(filename_);
            readShiftRegisterData(inputFileStream, shiftRegisters, startingStates);

            std::cout << "Number of shift registers: " << shiftRegisters << std::endl;
            for (int i = 0; i < shiftRegisters; i++) {
                std::cout << "Starting state " << (char)(i+65) << ": " << startingStates[i] << std::endl;
            }

            delete[] startingStates;
        }
    }

private:
    std::string filename_;

    void readShiftRegisterData(std::ifstream& inputFileStream, int& shiftRegisters, int*& startingStates) {
        // Read the first line.
        std::string line1;
        std::getline(inputFileStream, line1);

        // Split the line into tokens.
        std::stringstream sstream1(line1);
        std::string token1;
        std::getline(sstream1, token1, ':');
        std::getline(sstream1, token1, ':');

        // Convert the token to an int.
        shiftRegisters = std::stoi(token1);

        // Allocate memory for the starting states VLA.
        startingStates = new int[shiftRegisters];

        // Read the second line.
        std::string line2;
        std::getline(inputFileStream, line2);

        // Split the line into tokens.
        std::stringstream sstream2(line2);
        std::string token2;
        std::getline(sstream2, token2, ':');

        // Change the delimiter to a comma.
        sstream2.imbue(std::locale(""));

        // Get each token between the commas and convert to int.
        for (int i = 0; i < shiftRegisters; i++) {
            std::getline(sstream2, token2, ',');
            startingStates[i] = std::stoi(token2);
        }

        {
            std::string line3;
            std::getline(inputFileStream, line3); // Input: 1,0,1,1,0,0,0

            std::stringstream sstream3(line3);
            std::string token3;
            std::getline(sstream3, token3, ':'); // "Input"
            std::cout << "!" << token3 << "!" << std::endl;
        }
    }
};
#endif //FILEHANDLING_H