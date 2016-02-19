//сортировка подсчетом, время работы О( n^2 )
#include <iostream>
using namespace std;
void countingSort(int *array,int length) {
    int max=array[0];
    for (int i = 0; i < length; i++) {
            if (array[i]>max)
                max=array[i];
    }
    int *counter=new int[++max];
    for (int i = 0; i < max; i++) {
        counter[i]=0;
    }
    for (int i=0; i<length; i++){
        counter[array[i]]++;
    }
    int j=0;
    for (int i=0; i<max; i++){
        while(counter[i]>0){
            array[j++]=i;
            counter[i]--;
        }   
    }
}

int main(){

    int array[10]={8,7,7,5,4,8,8,5,6,3};
    countingSort(array,10);
    for (int i=0; i<10; i++){
        cout<<array[i]<<' ';
    }
    return 0;
}