//3 _2: Дан массив целых чисел A[0..n-1]. Известно, что на интевале [0..m] значения массива строго возрастают
//а на интервале [m..n-1] строго убывают. Найти m. Время работы O (log m)
//Входные данные: 2<=n<=10000 и элеметны массива
//Выходные данные: m

#include <iostream>

int search(int* A, int n) {
    int cur;
    int left = 0;
    int right = n;
    cur = 1;
    for (int i = 0; cur < n; i++) {
        if(A[cur - 1] > A[cur]) {
            left =  cur/2;
            right = cur;
            break;
        }
        cur*=2;
    }
    int m = (left + right) / 2;
    while (right - left > 1) {
        m = (left + right) / 2;
        //убывает
        if(A[m - 1] > A[m]) {
            right = m;
        }
        //возрастает
        else {
            left = m;
        }
    }
    return left;
}

int main() {
    int n, result;
    std::cin >> n;
    int* A = new int[n];
    for(int i = 0; i < n; i++)
        std::cin >> A[i];
    result = search(A, n);
    std::cout << result;
    delete[] A;
    return 0;
} 
