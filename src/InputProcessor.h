//
// Created by karol on 5/9/18.
//

#ifndef HEX_INPUTPARSER_H
#define HEX_INPUTPARSER_H
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Splitter.h"
#include "Parser.h"

class InputProcessor {
public:
    std::vector<std::vector<unsigned char>> processFile(std::string file_name);
    std::string slurp(std::ifstream& in);
    std::vector<std::vector<unsigned char>> processRawData(std::string input);
    void sortEvenAndOdd(std::vector<std::vector<unsigned char>> &v);
};


#endif //HEX_INPUTPARSER_H
