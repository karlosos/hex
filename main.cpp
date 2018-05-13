#include "src/InputProcessor.h"
#include "src/Output.h"

int main() {
    InputProcessor ip;
    std::vector<std::vector<unsigned char>> out = ip.processFile("input");
    Output o;
    o.outputToFile(out);
    return 0;
}