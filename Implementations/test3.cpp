#include<iostream>
#include<fstream>
#include "IO.h"
#include "algo.h"
int main() {
   std::vector<std::string> input;
   std::vector<int> gaps;
   readData(input);
   createNormalGaps(gaps, input.size());
   //  createKnuthGaps(gaps, input.size());
   // createSedgewickGaps(gaps, input.size());
   clock_t clock_start = clock();
    shellSort(input, gaps, compareStrings);
   clock_t clock_end = clock();
   double time_spent = (double)(clock_end - clock_start) / CLOCKS_PER_SEC;
   std::cout<<time_spent;
   writeData(input);
   return 0;
}