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
        int requiredRegisters = 4;
        int x;
        for (x = 0; x < requiredRegisters; x++) {
            ShiftRegister sf;
            sf.value = 0;
            shiftRegisters.push_back(sf);
        }

        InputString_ = InputString;

        int i=0;
        std::string configStringA="1001";
        std::string configStringB="1111";
        std::string configStringC="1111";
        std::string configStringD="0000";
        for (int j = 0; j < shiftRegisters.size(); j++) {
            if (configStringA.substr(j, 1) == "1") {
                shiftRegisterA.push_back(shiftRegisters[j]);
            }
            if (configStringB.substr(j, 1) == "1") {
                shiftRegisterB.push_back(shiftRegisters[j]);
            }
            if (configStringC.substr(j, 1) == "1") {
                shiftRegisterC.push_back(shiftRegisters[j]);
            }
            if (configStringD.substr(j, 1) == "1") {
                shiftRegisterD.push_back(shiftRegisters[j]);
            }
        }

        std::cerr << shiftRegisterA.size() << std::endl;
    }

    void Convert() {
        for (int i = 0; i < InputString_.length(); i++) {
            int InputValue = std::stoi(InputString_.substr(i, 1));

            for (int j = shiftRegisters.size() - 1; j > 0; j--) {
                shiftRegisters[j].value = shiftRegisters[j - 1].value;
            }
            shiftRegisters[0].value = InputValue;

            int result = 0;
            for (ShiftRegister shiftRegister : shiftRegisterA) {
                //result = ShiftRegister ^ result;
             }
            int A = shiftRegisters[0].value ^ shiftRegisters[1].value ^ shiftRegisters[2].value;
            int B = shiftRegisters[1].value ^ shiftRegisters[2].value;
            int C = shiftRegisters[0].value ^ shiftRegisters[2].value;

            std::cout << A << B << C;
        }
    }

private:
    std::vector<ShiftRegister> shiftRegisters;
    std::vector<ShiftRegister> shiftRegisterA;
    std::vector<ShiftRegister> shiftRegisterB;
    std::vector<ShiftRegister> shiftRegisterC;
    std::vector<ShiftRegister> shiftRegisterD;
    std::string InputString_;
};
#endif //ENCODER_H
