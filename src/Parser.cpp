//
// Created by karol on 5/13/18.
//

#include "Parser.h"

/**
 * Filter out all characters outside the range 0-F
 *
 * @param s
 * @return filtered string
 */
std::string Parser::filterString(std::string s) {
    std::string filtered_string = "";
    for (int i=0; i<s.length(); i++) {
        if (isxdigit(s.at(i)))
            filtered_string += s.at(i);
    }
    return filtered_string;
}

/**
 * Divide string into pairs
 *
 * @param s
 * @return
 */
std::vector<std::string> Parser::splitStringIntoPairs(std::string s) {
    std::vector<std::string> pairs;
    for (int i=0; i<s.length(); i += 2) {
        pairs.push_back(s.substr(i, 2));
    }
    return pairs;
}

/**
 * Covert collection of strings to collection of one-byte
 *
 * @param pairs
 * @return
 */
std::vector<unsigned char> Parser::convertStringPairsToBytes(std::vector<std::string> pairs) {
    std::vector<unsigned char> o;
    for (auto &i : pairs) {
        o.push_back(hexStringToInt(i));
    }
    return o;
}

/**
 * Convert string with hexadecimal digits to integer
 *
 * Two characters make up one number ("3" + "C" -> 3C)
 *
 * @param s
 * @return
 */
int Parser::hexStringToInt(std::string s) {
    return std::stoi(s, 0, 16);
}
