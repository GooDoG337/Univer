#include <iostream>
#include <cstdio>

int main() {
    if(std::FILE* f=std::fopen("input.txt","r"); f!=nullptr) {
        char buf[100];
        std::fscanf(f,"%99s", buf);
        //...
        for(const auto elm:buf) {
            std::cout << elm;
        }
        std::fclose(f);
    //ascii - 7 bit (1bayt), utf-8 - 8bit (1bayt)
        //utf-8/16/32 = 1 ili 2 bayta/2 ili 4 bayta/4 ili 8 bayt na symbol
    } else {
        std::cout << "File open failure\n";
    }
}
