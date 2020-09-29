#include<iostream>
#include<queue>
#include<vector>
#define MOD 10
#define DIGITS 11
void radixSort(std::vector<int> &array) {
    std::queue<int> digits[DIGITS];
    int length = array.size();
    int sizes[DIGITS] = {0};
    int negNumbers = 0;
    long digit_rank = 1, max_rank = 1;
    for(int i = 0; i < length; i++) {
        digits[0].push(array[i]);
    }
    sizes[0] = digits[0].size();
    while (sizes[0] != (length - negNumbers ) || digit_rank == 1) {
        for (int i = 0; i < DIGITS - 1; i++) {
            while(sizes[i] > 0) {
                int number = digits[i].front();
                digits[i].pop();
                if (abs(number) / digit_rank == 0 && number < 0) {
                    digits[10].push(number);
                    negNumbers++;
                } else {
                    int digit = (abs(number) / digit_rank) % MOD;
                    digits[digit].push(number);
                }
                sizes[i]--;
            }

        }
        digit_rank *= 10;
        for (int i = 0; i < DIGITS - 1; i++) {
            sizes[i] = digits[i].size();
        }
    }
    int negLength = digits[DIGITS - 1].size() - 1;
    int i = 0;
    while(negLength >= 0) {
        array[negLength--] = digits[DIGITS - 1].front();
        digits[DIGITS - 1].pop();
    }
    while(i < sizes[0]) {
        array[i + negNumbers] = digits[0].front();
        digits[0].pop();
        i++;
    }

}