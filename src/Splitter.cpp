//
// Created by karol on 5/13/18.
//

#include "Splitter.h"

/**
 * Divide array of numbers into two parts. First with even and second with odd number of ones.
 *
 * @param pairs
 * @return
 */
std::vector<std::vector<unsigned char>> Splitter::splitIntoEvenAndOdd(std::vector<unsigned char> &pairs) {
    std::vector<unsigned char> even;
    std::vector<unsigned char> odd;
    for (auto &i : pairs) {
        if (isEvenNumberOfOnes(i))
            even.push_back(i);
        else
            odd.push_back(i);
    }
    std::vector<std::vector<unsigned char>> output;
    output.push_back(even);
    output.push_back(odd);
    return output;
}

/**
 * Check if number of ones in a given byte is even
 *
 * @param n
 * @return
 */
bool Splitter::isEvenNumberOfOnes(unsigned char n) {
    if (__builtin_popcount(n) % 2 == 0)
        return true;
    else
        return false;
}