#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
void createNormalGaps(std::vector<int> &gaps, int dimension) {
    int k = dimension / 2;
    for (int i = k; i > 0; i/=2) {
        gaps.push_back(i);
    } 
}
void createKnuthGaps(std::vector<int> &gaps, int dimension) {
    for (int i = 1; i <= dimension / 2; i=(i * 3) + 1) {
        gaps.push_back(i);
    }
    std::reverse(gaps.begin(), gaps.end());
 }
 void createPrattGaps(std::vector<int> &gaps, int dimension) {
     int p = 0, q  = 0;
     int gap = 1;
     while (gap <= dimension) {
         gaps.push_back(gap);

     }
 }
void createSedgewickGaps(std::vector<int> &gaps, int dimension) {
    int gap = 1;
    int i = 1;
    while(gap <= dimension / 2) {
        gaps.push_back(gap);
        gap = pow(4, i) + 3 * pow(2, i - 1) + 1;
        i++;
    }
}