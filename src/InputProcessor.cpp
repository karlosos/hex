//
// Created by karol on 5/9/18.
//

#include "InputProcessor.h"

/**
 * Extract data from a file and process it.
 *
 * @param file_name
 * @return
 */
std::vector<std::vector<unsigned char>> InputProcessor::processFile(std::string file_name) {
    std::ifstream ifs (file_name, std::ifstream::in);
    std::string file = slurp(ifs);
    std::vector<std::vector<unsigned char>> out = processRawData(file);
    return out;
}

/**
 * Read file into string
 *
 * @param in
 * @return
 */
std::string InputProcessor::slurp(std::ifstream& in) {
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

/**
 *
 * @param input
 * @return
 */
std::vector<std::vector<unsigned char>> InputProcessor::processRawData(std::string input) {
    Splitter splitter;
    Parser parser;
    std::string s = parser.filterString(input);
    std::vector<unsigned char> pairs = parser.convertStringPairsToBytes(parser.splitStringIntoPairs(s));
    std::vector<std::vector<unsigned char>> even_and_odd = splitter.splitIntoEvenAndOdd(pairs);
    sortEvenAndOdd(even_and_odd);
    return(even_and_odd);
}


/**
 * Sort part with even numbers of ones in ascending order. Sort another part in descending order.
 * @param v
 */
void InputProcessor::sortEvenAndOdd(std::vector<std::vector<unsigned char>> &v) {
    std::sort(v.at(0).begin(), v.at(0).end());
    std::sort(v.at(1).begin(), v.at(1).end(), std::greater<unsigned char>());
}



