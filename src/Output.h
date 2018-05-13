//
// Created by karol on 5/13/18.
//

#ifndef HEX_OUTPUT_H
#define HEX_OUTPUT_H

#include <vector>
#include <fstream>

class Output {
public:
    void outputToFile(std::vector<std::vector<unsigned char>> &out);
private:
    void outputCollectionToFile(std::vector<unsigned char> o, std::string filename);
};


#endif //HEX_OUTPUT_H
