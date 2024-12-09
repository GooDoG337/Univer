#include <iostream>
#include <iterator>
#include <math.h>


size_t GetIndex(std::string primer, int SignIndex, bool LeftStart) // or RightEnd
{
    int it1 = SignIndex;
    if (LeftStart) {
        while ((primer[it1 - 1] >= '0' && primer[it1 - 1] <= '9') || (primer[it1 - 1] == '.' || primer[it1-1] == '-')) {
            it1--;
        }
        return it1;
    }
    else
    {
        while((primer[it1+1] >= '0' && primer[it1+1] <= '9') || (primer[it1+1] == '-' || primer[it1+1] == '.'))
        {
            it1++;
        }

        return it1;
    }
}
double GetNum(std::string primer, int SignIndex, bool Left)
{
    if(Left)
    {
        auto it1 = SignIndex;
        while ((primer[it1-1] >= '0' && primer[it1-1] <= '9') || primer[it1-1] == '.') {
            it1--;
        }
        bool IsPositive = true;
        if(it1 > 0)
        {
            if(primer[it1-1] == '-') {
                IsPositive = false;
            }
        }
        double num = 0;
        while(primer[it1] != '.' && primer[it1] != '*')
        {
            num*=10;
            num+=primer[it1]-48;
            it1++;
        }
        if(primer[it1] == '.')
        {
            it1++;
        }
        int digits = 1;
        while(primer[it1] != '*')
        {
            num += (primer[it1]-48)*pow(0.1,digits);
            digits++;
            it1++;
        }
        if(!IsPositive) {
            num*=-1;
        }
        return num;
    }
    else
    {
        bool IsPositive = true;
        int it1 = SignIndex+1;
        if(primer[it1] == '-')
        {
            IsPositive = false;
            it1++;
        }
        double num = 0;
        while(primer[it1] <= '9' && primer[it1] >= '0')
        {
            num*=10;
            num+=primer[it1]-48;
            it1++;
        }
        std::cout << "NUM88 = " << num << '\n';

        if(primer[it1] == '.')
        {
            it1++;
        }
        int digits2 = 1;
        while(primer[it1] >= '0' && primer[it1] <= '9')
        {
            num += (primer[it1]-48)*pow(0.1,digits2);
            digits2++;
            it1++;
        }
        if(!IsPositive) {
            num*=-1;
        }
        return num;
    }
}
int main() {
    std::string primer;
    std::getline(std::cin, primer);
    int I_Backup;
    std::cout << "primer: " << primer << '\n';
    int SignIndex = primer.find('*');
    while(SignIndex != -1) {
        primer.replace(GetIndex(primer, SignIndex, true), GetIndex(primer, SignIndex, false), std::to_string(GetNum(primer, SignIndex, true)*GetNum(primer, SignIndex, false) ));
        return 0;
        SignIndex = primer.find('*');
    }
    return 0;

    /*int I_Backup2;
    IsPositive = true;
    it1++;

    if(primer[it1] == '-')
    {
        IsPositive = false;
        it1++;
    }
    double num2 = 0;
    while(primer[it1] != '.')
    {
        num2*=10;
        num2+=primer[it1]-48;
        it1++;
    }
    if(primer[it1] == '.')
    {
        it1++;
    }
    int digits2 = 1;
    std::cout << "Num2 = " << num2 << '\n';
    while(primer[it1] >= '0' && primer[it1] <= '9')
    {
        num2 += (primer[it1]-48)*pow(0.1,digits2);
        digits2++;
        it1++;
    }
    I_Backup2 = it1;
    if(!IsPositive) {
        num2*=-1;
    }
    std::cout << num2 << '\n';
    std::cout << I_Backup << '\n';
    std::cout << I_Backup2 << '\n';
    primer.replace(I_Backup, I_Backup2, std::to_string(num*num2));
    std::cout << "primer: " << primer << '\n';*/

    return 0;
}