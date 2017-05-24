// 5_1. Первые k элементов длинной последовательности.
//Дана очень длинная последовательность целых чисел длины n. Требуется вывести в
//отсортированном виде её первые k элементов. Последовательность может не помещаться в
//память. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.

#include <iostream>

void merge(int merged[], int length, int L[], int lengthL, int R[], int lengthR){
  int i = 0;
  int j = 0;
  while(i < lengthL || j < lengthR) {
    if (i < lengthL && j < lengthR) {
      if(L[i] <= R[j]){
        merged[i + j] = L[i];
        i++;
      }
      else{
        merged[i + j] = R[j];
        j++;
      }
    }
    else if(i < lengthL){
      merged[i + j] = L[i];
      i++;
    }
    else if(j < lengthR){
      merged[i + j] = R[j];
      j++;
    }
  }
}

void mergeSort(int array[], int length)
{
  if(length > 1) {
    int middle = length / 2;
    int rest = length - middle;
    int* L = new int[middle];
    int* R = new int[rest];
    for(int i = 0; i < length; i++){
      if(i < middle){
        L[i] = array[i];
      }
      else{
        R[i - middle] = array[i];
      }
    }
    mergeSort(L,middle);
    mergeSort(R,rest);
    merge(array, length, L, middle, R, rest);
    delete[] L;
    delete[] R;
  }
}
 


int main() {
    int i, n, k ,cnt;
    std::cin >> n >> k;
    int* array = new int[2*k];
    for (i = 0; i < k; i++) {
        std::cin >> array[i];
    }
    mergeSort(array,k);
    for (i = k ; i < n; i++){
      if (cnt == k) {
        cnt = 0;
        mergeSort(array,2*k);
      }
        std::cin >> array [k + cnt];
        cnt++;
    }
    mergeSort(array,2*k);
    for (int i = 0; i < k; i++){
        std::cout << array[i] << ' ';
    }
    delete[] array;
    return 0;
} 
