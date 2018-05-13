//
// Created by karol on 5/13/18.
//

#ifndef HEX_SPLITTER_H
#define HEX_SPLITTER_H

#include <vector>

class Splitter {
public:
    std::vector<std::vector<unsigned char>> splitIntoEvenAndOdd(std::vector<unsigned char> &pairs);
    bool isEvenNumberOfOnes(unsigned char n);
};


#endif //HEX_SPLITTER_H
