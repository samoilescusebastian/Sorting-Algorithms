#include<iostream>
#include<fstream>
#include "../timSort.h"
#include "../comparators.h"
#include "../IO.h"
int main() {
   std::vector<int> input;
   std::string integers_input_file_name = "../../Tests/randomData/randomIntegersTest4";
   std::ifstream input_file;
   input_file.open(integers_input_file_name);
   readData(input, input_file);
   clock_t clock_start = clock();
   timSort(input, compareIntegers);
   clock_t clock_end = clock();
   double time_spent = (double)(clock_end - clock_start) / CLOCKS_PER_SEC;
   std::cout<<time_spent;
   writeData(input);
   return 0;
}