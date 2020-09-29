#include <iostream>
#include <string.h>
#include <fstream>
#define limitLen 30
#define tests 5
#define offset 5
void getRandomString(const int len, std::ofstream &out_file) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        out_file<<alphanum[(rand() % (sizeof(alphanum) - 1))];
    }

    out_file<<"\0";
    out_file<<"\n";
}
void generateRandomStrings(int dimension, std::ofstream &out_file) {
    out_file<<dimension<<"\n";
    for (int i = 0; i < dimension; i++) {
        int len = rand() % limitLen + offset;
        getRandomString(len, out_file);
    }

}
int main() {
      std::ofstream out_file;
      std::string file_name = "randomStringsTest";
    int dimensions[] = {100, 100000, 500000, 750000, 1000000};
    for (int i = 0; i < tests; i++) {
        char test_number = i + '0';
        out_file.open(file_name + test_number);
        generateRandomStrings(dimensions[i], out_file);
        out_file.close();
    }
    return 0;
}