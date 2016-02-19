//сортировка слиянием, время работы O( nlog(n) )
#include <iostream>
using namespace std;
void merge(int merged[], int length, int L[], int lengthL, int R[], int lengthR){
  int i = 0;
  int j = 0;
  while(i<lengthL||j<lengthR){
    if (i<lengthL & j<lengthR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lengthL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lengthR){
      merged[i+j] = R[j];
      j++;
    }
  }
}

void mergeSort(int array[], int length)
{
  if(length>1){
    int middle = length/2;
    int rest = length-middle;
    int* L = new int[middle];
    int* R = new int[rest];
    for(int i=0;i<length;i++){
      if(i<middle){
        L[i] = array[i];
      }
      else{
        R[i-middle] = array[i];
      }
    }
    mergeSort(L,middle);
    mergeSort(R,rest);
    merge(array, length, L, middle, R, rest);
  }
}
 


int main() {   
    int n;
    int array[100]; 
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    mergeSort(array,5);
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}