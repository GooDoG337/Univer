//
// Created by shishik4life on 25.02.2025.
//

#ifndef dateCheck_h
#define dateCheck_h

#include <string>
#include <regex>
namespace dateCheck
{
    bool isValidDate(const std::string& date)
    {
        return std::regex_match(date, std::regex{"^((0[1-9]|[1-2]\\d|3[0-1])(?=\\.01|\\.03|\\.05|\\.07\\.08\\.10\\.12)|(0[1-9]|[1-2]\\d|30)(?=\\.04|\\.06|\\.09|\\.11)|(0[1-9]|[1-2][0-8])(?=\\.02)|(29)(?=\\.02\\.[1-9]\\d(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)))\\.(1[0-2]|0[1-9])\\.[1-9]\\d{3}\\s([0-1]\\d|2[0-3]):[0-5][0-9]$"});
    }
}

#endif //dateCheck_h
