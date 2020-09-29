#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "IO.h"
int main() {
    std::vector<std::string> array;
    std::ifstream input_file;
    std::string input_file_name = "../Tests/reversedSortedStrings/reversedSortedStringsTest4";
    input_file.open(input_file_name);
    readData(array, input_file);
    std::sort(array.begin(), array.end());
    writeData(array);
}