//сортировка вставкой, время работы O(n^2)
#include <iostream>
using namespace std;
int main(){
    int key;
    int array[5]={5,4,3,2,1};
    for(int j=1; j<5; j++){
        int i=j-1;
        key=array[j];
        while(i>=0 && array[i]>key){
            array[i+1]=array[i];
            i--;
        }
        array[i+1]=key;
       
    }
    for(int i=0; i<5; i++){
        cout<<array[i]<<' ';
    }
    return 0;
}