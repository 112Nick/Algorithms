//сортировка выбором, время работы О( n^2 )
#include <iostream>
#include <memory>
using namespace std;
void selectionSort(int array[],int length) {
    for (int i = 0; i < length; i++) {
        int maxindex=0;
        for (int j = 0; j < length-i; j++) {
            if (array[j]>array[maxindex])
                maxindex=j;
            swap(array[length-i-1],array[maxindex]);
        }
    }
}

int main(){
    int array[5]={4,5,3,2,1};
    selectionSort(array,5);
    for (int i=0; i<5; i++){
        cout<<array[i]<<' ';
    }
    return 0;
}