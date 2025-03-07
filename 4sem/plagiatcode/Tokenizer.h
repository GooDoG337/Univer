#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <fstream>
enum class TOKEN;

struct Token;

class Tokenizer
{
    std::fstream file;
    size_t prevPos;
public:
    Tokenizer(std::string fileName);
    auto getWithoutWhiteSpace();
    auto getToken();
    auto hasMoreTokens();
    void rollBackToken();

    /*
        "": String begin?
        {}: Object
        []: List
        num: number
        
     */
};
#endif //TOKENIZER_H
