#include<iostream>
#include<algorithm>
int compareIntegers(int a, int b) {
    return a - b;
}
int compareStrings(std::string a, std::string b) {
    return a.compare(b);
}