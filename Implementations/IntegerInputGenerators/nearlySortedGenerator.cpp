#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#define tests 5
#define offset 135000000
#define maxPerm 1000
#define maxLen 10

void generateNearlySortIntegers(std::vector<int> &numbers, std::ofstream &out_file) {
    int dimension = numbers.size();
    out_file<<dimension<<" ";
    std::sort(numbers.begin(), numbers.end());
    int perm = dimension * 0.02;
    int max_perm_len = dimension * 0.1;
    if (perm > maxPerm) {
        perm = maxPerm;
    }
    if (max_perm_len > maxLen) {
        max_perm_len = maxLen;
    }
    int first_index = rand() % dimension;
    int last_index = rand() % dimension;
    int perm_len;
    while (perm) {
        perm_len = rand() % max_perm_len + 1;
        first_index = rand() % dimension;
        last_index = rand() % dimension;
        for (int i = 0; i < perm_len && first_index + i < dimension
                        && last_index + i < dimension; i++) {
            std::swap(numbers[first_index + i], numbers[last_index + i]);
        }
      perm--;

    }
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
    std::string output_file_name = "nearlySortedIntegersTest";
    std::string input_file_name = "randomIntegersTest";
    std::vector<int> numbers;
    for (int i = 0; i < tests; i++) {
        char test_number = i + '0';
        input_file.open(input_file_name + test_number);
        out_file.open(output_file_name + test_number);
        readData(numbers, input_file);
        generateNearlySortIntegers(numbers, out_file);
        numbers.clear();
        out_file.close();
        input_file.close();
    }
}