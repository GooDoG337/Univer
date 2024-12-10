//
// Created by stud-16 on 12/10/24.
//

#include "calculation.h"

namespace calculate {
    int GetRightNum(int SignIndex, std::string expression) {
        int num = 0;
        bool isPositive = true;
        if(expression[SignIndex+1] ==  '-') {
            isPositive = false;
            SignIndex++;
        }
        while(expression[SignIndex+1] <= '9' && expression[SignIndex+1] >= '0') {
            num*=10;
            SignIndex++;
            num += expression[SignIndex]-48;
        }
        if(isPositive) {
            return num;
        }
        return -1*num;
    }
    int GetLeftNum(int SignIndex, std::string expression) {
        int num = 0;
        int digit = 1;
        while(expression[SignIndex-1] <= '9' && expression[SignIndex-1] >= '0') {
            SignIndex--;
            num += (expression[SignIndex]-48)*digit;
            digit*=10;
        }
        if(expression[SignIndex-1] ==  '-') {
            return -1*num;
        }
        return num;
    }

    size_t GetLeftStart(int SignIndex, std::string expression) {
        while(expression[SignIndex-1] <= '9' && expression[SignIndex-1] >= '0') {
            SignIndex--;
        }
        if(expression[SignIndex-1] == '-') {
            SignIndex--;
        }
        return SignIndex;
    }
    size_t GetRightEnd(int SignIndex, std::string expression) {
        if(expression[SignIndex+1] == '-') {
            SignIndex++;
        }
        while(expression[SignIndex+1] <= '9' && expression[SignIndex+1] >= '0') {
            SignIndex++;
        }
        return SignIndex;
    }

    bool IsValid(std::string expression) {
        size_t indx = 0;
        while(indx != expression.size()-1) {
            indx++;
            if((expression[indx] > '9' || expression[indx] < '0') && (expression[indx] != '-' && expression[indx] != '+' && expression[indx] != '/' &&expression[indx] != '*'))
            {
                return false;
            }
        }
        return 1;
    }
} // calculate