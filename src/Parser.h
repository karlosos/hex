//
// Created by karol on 5/13/18.
//

#ifndef HEX_PARSER_H
#define HEX_PARSER_H
#include <string>
#include <vector>

class Parser {
public:
    std::string filterString(std::string s);
    std::vector<std::string> splitStringIntoPairs(std::string s);
    std::vector<unsigned char> convertStringPairsToBytes(std::vector<std::string> pairs);
    int hexStringToInt(std::string s);
};


#endif //HEX_PARSER_H
