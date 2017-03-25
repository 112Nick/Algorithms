//В большой IT-фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с
//желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
//Число заявок ≤ 100000.
//Формат входных данных: Вход содержит только пары целых чисел — начала и концы заявок.
//Формат выходных данных: Выход должен содержать натуральное число — максимальное число заявок.

#include<iostream>

struct pair{
    int start;
    int end;
};

void swap(pair& a, pair& b) {
    pair buf = a;
    a = b;
    b = buf;
}

void quickSort(pair*& a,int l, int r) {
    pair x = a[l + (r - l) / 2];
    int i = l;
    int j = r;
    while(i <= j) {
        while(a[i].end < x.end) 
            i++;
        while(a[j].end > x.end)
            j--;
        if(i <= j) {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (i<r) {
        quickSort(a, i, r);        
    } 
    
    if (l<j) {
        quickSort(a, l, j);            
    }    
}

void resize(pair*& input, int& size) {
    pair* buf = new pair[size*2];
    for(int i = 0; i < size; i++) {
        buf[i] = input[i];
    }
    delete[] input;
    input = buf;
    size *= 2;
}

int count(pair* input, int size) {
    int result = 1;
    int prev = 0;
    for (int i = 1; i < size; i++) {
       if(input[i].start >= input[prev].end) {
            result++;
            prev = i;
       }    
    }
    return result;
}


int main() {
    int size = 10;
    int counter = 0;
    pair* input = new pair[size];
    while(std::cin) {
        std::cin >> input[counter].start >> input[counter].end;
        counter++;
        if(counter == size - 1) {
            resize(input, size);
        }
    }
    counter--;
    quickSort(input, 0, counter - 1);
    std::cout << count(input, counter);
    delete[] pair;
    return 0;
} 

