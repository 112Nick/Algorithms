//Корзинная сорировка, время работы O( n^2 )
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void bucketSort (vector<int> &array){
    int min,max,cnt,numOfBucket;
    min=array[0];
    max=min;
    for (int i=0; i<array.size(); i++){
        if (array[i]>max)
            max=array[i];
        if (array[i]<min)
            min=array[i];
    }
    numOfBucket=(max-min)/5+1;
    vector<vector<int>> buckets(numOfBucket);
    for (int i=0; i<array.size(); i++){
        int j=(array[i]-min)/5;
        buckets[j].push_back(array[i]);
    }
    auto it=array.begin();
    for (int i=0; i< numOfBucket; i++){
        sort(buckets[i].begin(), buckets[i].end());
        for (int j=0; j<buckets[i].size(); j++){
            *it=buckets[i][j];
            it++;
        }
    }
}
int main() {
    vector<int> array(10);
    for (int i=0; i<10; i++)
        cin>>array[i];
    bucketSort(array);
    for (int i=0; i<10; i++){
        cout<<array[i]<<' ';
    }
    return 0;
}