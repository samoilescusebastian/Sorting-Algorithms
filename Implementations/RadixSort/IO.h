#include <iostream>
#include <vector>
#include <fstream>
template<typename T>
void readData(std::vector<T> &input, std::ifstream &input_file) {
    int dimension;
    T data;
    input_file>>dimension;
    for (int i = 0; i < dimension; i++) {
        input_file>>data;
        input.push_back(data);
    }
}
template<typename T>
void writeData(std::vector<T> &input) {
    std::ofstream out_file;
    out_file.open("sortedData");
    for (int i = 0; i < input.size(); i++) {
        out_file<<input[i]<<std::endl;
    }
}