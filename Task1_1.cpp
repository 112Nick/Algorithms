//1_1: Найти, на сколько нулей оканчивается n!
//Входные данные: n
//Выходные данные: число нулей в конце n!- переменная result

#include <iostream>

int func(int n) {
    int count2 = 0;
    int count5 = 0;

    for(int i = 1; i <= n; i++) {
        int multiplier = i;
        //Считаем сколько в текущем множетеле 2
        while(multiplier % 2 == 0){
            multiplier /= 2;
            count2++;
        }
        //Считаем сколько в текущем множетеле 5
        while(multiplier % 5 == 0){
            multiplier /= 5;
            count5++;
        }
    }
    //Возвращаем наименьшее число, так как 0 в конце числа дает пара 2*5
    if(count2 < count5)
        return count2;
    else
        return count5;
}

int main() {
    int n, result;
    std::cin >> n;
    result = func(n);
    std::cout << result;
    return 0;
} 
