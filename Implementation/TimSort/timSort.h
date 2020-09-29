#include <iostream>
#include <vector>
#include <algorithm>
#define RUN 32
template<typename type>
void insertionSort(std::vector<type> &array, int left, int right, int(*f)(type a, type b)) {   
    for (int i = left + 1; i <= right; i++) {
        type temp = array[i];
        int j = i - 1;
        while (j >= left && f(array[j], temp) >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
template<typename type>
void merge(std::vector<type> &array, int left, int middle, int right, int(*f)(type a, type b)) {
    int len1 = middle - left + 1, len2 = right - middle;
    std::vector<type> left_array(len1), right_array(len2);
    for (int i = 0; i < len1; i++) {
        left_array[i] = array[left + i];
    }
    for (int i = 0; i < len2; i++) {
        right_array[i] = array[middle + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < len1 && j < len2)  {
        if (f(left_array[i],right_array[j]) <= 0) {
            array[k++] = left_array[i++];
        }
        else {
            array[k++] = right_array[j++];
        }
    }
    while (i < len1) {
        array[k++] = left_array[i++];
    }
    while (j < len2) {
        array[k++] = right_array[j++];
    }
}
template <typename type>
void timSort(std::vector<type> &array, int(*f)(type a, type b)) {
    int dimension = array.size();
    // sortez secventele de lungime run
    for (int i = 0; i < dimension; i += RUN) {
        insertionSort(array, i, std::min((i + 31), (dimension - 1)), f);
    }

    // incep sa unesc secventele de lunigme 32
    // pentru a obtine lungime de 64, 128 ..
    for (int size = RUN; size < dimension; size = 2 * size) {
        // aleg inceputul secventei din stanga.
        // se vor uni secventele array[left..left+size-1] si array[left+size, left+2*size-1]
        // dupa fiecare unire vom creste marimea secventei ce va fi unita
        for (int left = 0; left < dimension; left += 2 * size) {
            // cautam finalul secventei din dreapta
            // mijlocul va reprezenta sfarsitul, respectiv inceputul celor doua secvente
            int middle = std::min((left + size - 1), (dimension - 1));
            int right = std::min((left + 2 * size - 1), (dimension - 1));
            merge(array, left, middle, right, f);
        }
    }
}
