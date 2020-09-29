#include <cstdio>
#include <string>
#include <vector>
#define CHAR_NUMBERS 257
int getMax(std::vector<std::string> strings){
    int max = strings[0].size();
    for (int i = 1; i < strings.size(); i++){
        if (strings[i].size() > max)
            max = strings[i].size();
    }
    return max;
}

void countSort(std::vector<std::string> &strings, int position){
    int *frequency = NULL;
    int size = strings.size();
    std::string *new_order = new std::string[size];
    frequency = new int[CHAR_NUMBERS];


    for (int i = 0; i < CHAR_NUMBERS; i++){
        frequency[i] = 0;
    }
    for (int j = 0; j <size; j++){   
        frequency[position < strings[j].size() ? strings[j][position] + 1 : 0]++;
    }

    for (int char_index = 1; char_index < CHAR_NUMBERS; char_index++){
        frequency[char_index] += frequency[char_index - 1];
    }

    for (int i = size - 1; i >= 0; i--){
        new_order[frequency[position < strings[i].size() ? strings[i][position] + 1 : 0] - 1] = strings[i];
        frequency[position < strings[i].size()   ? strings[i][position] + 1 : 0]--;
    }

    for (int i = 0; i < size; i++){
        strings[i] = new_order[i];
    }

    // eliberarea memoriei
    delete[] new_order;
    delete[] frequency;
}


void radixSort(std::vector<std::string> &b){
    int max = getMax(b);
    for (int digit = max; digit > 0; digit--){
        countSort(b, digit - 1);
    }

}