#include <cstdio>
#include <string>
#include "../IO.h"
#include "stringRadixSort.h"

int main() {
   std::vector<std::string> input;
   std::string input_file_name = "../../Tests/randomStrings/randomStringsTest4";
   std::ifstream input_file;
   input_file.open(input_file_name);
   readData(input, input_file);
   clock_t clock_start = clock();
    radixSort(input);
   clock_t clock_end = clock();
   double time_spent = (double)(clock_end - clock_start) / CLOCKS_PER_SEC;
   std::cout<<time_spent;
   writeData(input);
   return 0;

}