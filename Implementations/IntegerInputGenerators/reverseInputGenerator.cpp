#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#define tests 5
#define offset 135000000
void generateReverseSortedIntegers(std::vector<int> &numbers, std::ofstream &out_file) {
    int dimension = numbers.size();
    out_file<<dimension<<" ";
    std::sort(numbers.begin(), numbers.end(), std::greater<>());
     for (int i = 0; i < numbers.size(); i++) {
        out_file<<numbers[i]<<" ";
    }
}
void readData(std::vector<int> &numbers, std::ifstream &input_file) {
    int dimension;
    int number;
    input_file>>dimension;
    for (int i = 0; i < dimension; i++) {
        input_file>>number;
        numbers.push_back(number);
    }
}
int main() {
    std::ofstream out_file;
    std::ifstream input_file;
    std::string output_file_name = "reversedSortedIntegersTest";
    std::string input_file_name = "randomIntegersTest";
    std::vector<int> numbers;
    for (int i = 0; i < tests; i++) {
        char test_number = i + '0';
        input_file.open(input_file_name + test_number);
        out_file.open(output_file_name + test_number);
        readData(numbers, input_file);
        generateReverseSortedIntegers(numbers, out_file);
        numbers.clear();
        out_file.close();
        input_file.close();
    }
}