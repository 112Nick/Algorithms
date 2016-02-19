//сортировка пузырьком, время работы О( n^2 )
#include <iostream>
#include <memory>
using namespace std;
void bubbleSort(int array[],int length) {
    for (int i = 0; i < length-1; i++) {
         for (int j = 0; j < length-i-1; j++) {
            if (array[j] > array[j+1]) 
                swap(array[j],array[j+1]);
        }
    }
}

int main(){
    int array[5]={5,4,3,2,1};
    bubbleSort(array,5);
    for (int i=0; i<5; i++){
        cout<<array[i]<<' ';
    }
    return 0;
}