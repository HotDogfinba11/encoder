//
// Created by Oliver Walton on 01/11/2023.
//

#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <vector>
#include "ShiftRegister.h"

class Solution {
public:
    Solution(std::string InputString) {
        int requiredRegisters = 3;
        int x;
        for (x = 0; x < requiredRegisters; x++) {
            ShiftRegister sf;
            sf.value = 0;
            shiftRegisters.push_back(sf);
        }
        InputString_ = InputString;
    }

    void CreateRegisterSubset() {
        std::string configStringA="111";
        std::string configStringB="011";
        std::string configStringC="101";
        std::string configStringD="000";
        shiftRegistersA.clear();
        shiftRegistersB.clear();
        shiftRegistersC.clear();
        shiftRegistersD.clear();
        for (int j = 0; j < shiftRegisters.size(); j++) {
            if (configStringA.substr(j, 1) == "1") {
                shiftRegistersA.push_back(shiftRegisters[j]);
            }
            if (configStringB.substr(j, 1) == "1") {
                shiftRegistersB.push_back(shiftRegisters[j]);
            }
            if (configStringC.substr(j, 1) == "1") {
                shiftRegistersC.push_back(shiftRegisters[j]);
            }
        }
    }

    void Convert() {
        for (int i = 0; i < InputString_.length(); i++) {
            int InputValue = std::stoi(InputString_.substr(i, 1));

            for (int j = shiftRegisters.size() - 1; j > 0; j--) {
                shiftRegisters[j].value = shiftRegisters[j - 1].value;
            }
            shiftRegisters[0].value = InputValue;

            CreateRegisterSubset();

            int A = shiftRegistersA[0].value;
            for (int k = 1; k < shiftRegistersA.size(); k++) {
                A ^= shiftRegistersA[k].value;
            }

            int B = shiftRegistersB[0].value;
            for (int k = 1; k < shiftRegistersB.size(); k++) {
                B ^= shiftRegistersB[k].value;
            }

            int C = shiftRegistersC[0].value;
            for (int k = 1; k < shiftRegistersC.size(); k++) {
                C ^= shiftRegistersC[k].value;
            }
            std::cout << A << B << C << std::endl;
        }
    }

private:
    std::vector<ShiftRegister> shiftRegisters;
    std::vector<ShiftRegister> shiftRegistersA;
    std::vector<ShiftRegister> shiftRegistersB;
    std::vector<ShiftRegister> shiftRegistersC;
    std::vector<ShiftRegister> shiftRegistersD;
    std::string InputString_;
};
#endif //ENCODER_H
