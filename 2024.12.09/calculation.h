//
// Created by stud-16 on 12/10/24.
//

#ifndef CALCULATION_H
#define CALCULATION_H
#include <string>
namespace calculate {
    int GetRightNum(int SignIndex, std::string expression);
    int GetLeftNum(int SignIndex, std::string expression);
    size_t GetLeftStart(int SignIndex, std::string expression);
    size_t GetRightEnd(int SignIndex, std::string expression);

    bool IsValid(std::string expression);
} // calculate

#endif //CALCULATION_H
