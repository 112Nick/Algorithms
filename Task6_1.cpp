//Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков
//пирамиду.
//Формат входных данных:
//На вход подается количество кубиков N.
//Формат выходных данных:
//Вывести число различных пирамид из N кубиков.
//6_1.​ Высокая пирамида. ​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.
//N ≤ 200

#include<iostream>



long long prev(long long** array, int i, int j) {
    if (j > i) {
        j = i;
    }
    return array[i][j];
}

long long count(int n){
    long long result;
    long long** array = new long long*[n + 1];
    for (long long i = 0; i < n + 1; i++) {
        array[i] = new long long[n + 1];
    }
    array[0][0] = 1;
    for(int i = 0; i < n + 1 ; i++) {
        for(int j = 1; j < i + 1; j++) {
             array[i][j] = prev(array, i, j - 1) + prev(array, i - j, j);
        }
    }
    result = array[n][n];
    for (int i = 0; i < n + 1; i++) {
        delete[] array[i];
    }
    delete[] array;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count(n);
    return 0;
} 
