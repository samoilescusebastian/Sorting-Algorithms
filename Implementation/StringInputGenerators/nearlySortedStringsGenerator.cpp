
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define test 5
std::vector<std::string> readData(std::ifstream &input_file) {
    std::vector<std::string> strings;
    std::string string;
    int dimension;
    input_file>>dimension;
    for (int j = 0; j < dimension; j++) {
        getline(input_file, string);
        strings.push_back(string);
    }
    return strings;
    
}
void saveData(std::vector<std::string> strings, std::ofstream &output_file) {
    output_file<<strings.size();
    for (int i = 0; i < strings.size(); i++) {
        output_file<<strings[i]<<"\n";
    }
}
void generateNearlySortedStrings(std::vector<std::string> &strings) {
    int dimension = strings.size();
    int sorted_set_dimension = dimension * 0.46;
    int random_set_dimension = dimension * 0.02;
    int index = 0;
    while (index < strings.size()) {
        int sorted_len = std::min(rand() % sorted_set_dimension, dimension - index);
        std::sort(strings.begin() + index, strings.begin() + index + sorted_len);
        index += sorted_len;
        int random_len = std::min(rand() % random_set_dimension, dimension - index);
        index += random_len;
    }
}
int main() {
    std::vector<std::string> strings;
    std::ifstream input_file;
    std::ofstream output_file;
    std::string file_name_input = "randomStringsTest";
    std::string file_name_output = "nearlySortedStringsTest";
    std::string string;
    for (int i = 0; i < test; i++) {
        char test_number = i + '0';
        input_file.open(file_name_input + test_number);
        strings = readData(input_file);
        generateNearlySortedStrings(strings);
        output_file.open(file_name_output + test_number);
        saveData(strings, output_file);
        input_file.close();
        output_file.close();
        
    }
    return 0;
    

}