#include<iostream>
#include<fstream>
#include<string>
#define tests 5
#define MAX_DIGITS_REMOVED 8
#define offset 1350000000
int amortization;
int get_amortization(int digits) {
    int amortization = 1;
    while(digits) {
        amortization *= 10;
        digits--;
    }
    return amortization;
}
void generateRandomIntegers(int dimension, std::ofstream &out_file) {
    out_file<<dimension<<" ";
    for (int i = 0; i < dimension; i++) {
       int digits_removed = rand() % MAX_DIGITS_REMOVED; 
       int number = (rand() - offset) / get_amortization(digits_removed);
       out_file<<number<<" ";
    }
}
int main() {
    std::ofstream out_file;
    std::string file_name = "randomIntegersTest";
    int dimensions[] = {100, 100000, 500000, 750000, 1000000};
    for (int i = 0; i < tests; i++) {
        char test_number = i + '0';
        out_file.open(file_name + test_number);
        generateRandomIntegers(dimensions[i], out_file);
        out_file.close();
    }
}