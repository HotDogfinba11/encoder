//
// Created by Oliver Walton on 01/11/2023.
//

#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <vector>
#include "ShiftRegister.h"

class Encoder {
public:
    Encoder(std::string InputString) {
        int requiredRegisters = 3;
        int x;
        for (x = 0; x < requiredRegisters; x++) {
            ShiftRegister sf;
            sf.value = 0;
            shiftRegisters.push_back(sf);
        }
        InputString_ = InputString;
        vConfigs.push_back("111");
        vConfigs.push_back("011");
        vConfigs.push_back("101");
    }

    bool Convert() {
        for (int i = 0; i < InputString_.length(); i++) {
            RegisterShift(i);

            CreateRegisterSubset();

            CalcXOR();
        }

        return true;
    }

private:
    std::vector<ShiftRegister> shiftRegisters;
    std::vector<std::string> vConfigs;
    std::vector<std::vector<ShiftRegister> > registerSubsets;
    std::string InputString_;

    void CalcXOR() {
        for (int k = 0; k < registerSubsets.size(); k++) {
            //read the bit required bit from subset of values
            int calcValue = registerSubsets[k][0].value;
            //loop through the rest of the subset of bits, xoring them
            for (int l = 1; l < registerSubsets[k].size(); l++) {
                calcValue ^= registerSubsets[k][l].value;
            }
            std::cout << calcValue;
        }
        std::cout << ",";
    }

    void CreateRegisterSubset() {
        registerSubsets.clear();

        for (int i=0; i < vConfigs.size(); i++) {
            CreateRegisterLoop(vConfigs[i],i);
        }
    }

    void RegisterShift(int i) {
        int InputValue = std::stoi(InputString_.substr(i, 1));
        for (int j = shiftRegisters.size() - 1; j > 0; j--) {
            shiftRegisters[j].value = shiftRegisters[j - 1].value;
        }
        shiftRegisters[0].value = InputValue;
    }

    void CreateRegisterLoop(std::string configString,int i){
        registerSubsets.push_back(std::vector<ShiftRegister>());
        for (int j = 0; j < shiftRegisters.size(); j++) {
            if (configString.substr(j, 1) == "1") {
                registerSubsets[i].push_back(shiftRegisters[j]);
            }
        }
    }
};
#endif //ENCODER_H
