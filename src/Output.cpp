//
// Created by karol on 5/13/18.
//

#include "Output.h"

/**
 * Output even and odd to files
 *
 * @param out
 */
void Output::outputToFile(std::vector<std::vector<unsigned char>> &out) {
    outputCollectionToFile(out.at(0), "even");
    outputCollectionToFile(out.at(1), "odd");
}

/**
 * Output collection to file
 *
 * @param o
 * @param filename
 */
void Output::outputCollectionToFile(std::vector<unsigned char> o, std::string filename) {
    std::ofstream output;
    output.open(filename);
    for (auto &i : o) {
        output << std::hex << (int)i << '\n';
    }
    output.close();
}