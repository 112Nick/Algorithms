//5_4. Вычисление выражения.
//Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись.
//Выражение не содержит отрицительных чисел.
//Количество операций ≤ 100.
//Формат входных данных. Строка, состоящая их символов “0123456789+*()”
//Гарантируется, что входное выражение корректно, нет деления на 0, вычислимо в целых числах. Деление целочисленное.
//Формат выходных данных: Значение выражения.
#include <iostream>

#include <math.h>
#define MAX_SIZE 101


class Stack {	
	private:
		int* array;
		int size;
		int cur;
	public:
		Stack();
		void push(int c);
		int pop();
		int top();
		bool isEmpty();
};

Stack::Stack() {
	array = new int[MAX_SIZE];
	size = 0;
}

int Stack::pop() {
	int val;
	val = array[size - 1];
	size--;
	return val;
}

int Stack::top() {
	int val;
	val = array[size - 1];
	return val;
}


void Stack::push(int c) {
	array[size] = c;
	size++;
}

bool Stack::isEmpty() {
	if(size == 0)
		return true;
	return false;	
}

int getPriority(int operand) {
	if(operand == -1)
		return 4;
	if(operand == -2)
		return 4;
	if(operand == -3)
		return 3;
	if(operand == -4)
		return 3;	
	return 0;
	
}

int count(int* output, int cnt) {
   Stack stack;
   int a, b;
   for(int i = 0; i < cnt; i++) {
        if(output[i] >= 0) {
            stack.push(output[i]);
        }
        else {
            switch (output[i]) {
                case -4:
					a = stack.pop();
					b = stack.pop();
                    stack.push(a + b);
					break;
                case -3:
					a = stack.pop();
					b = stack.pop();
                    stack.push(b - a);
					break;
                case -2:
					a = stack.pop();
					b = stack.pop();
                    stack.push(a * b);
					break;
                case -1:
					a = stack.pop();
					b = stack.pop();
                    stack.push(b / a);
					break;
            }
        }
   }
   return stack.pop();
}


int toPostfix(char* input, int length) {
	int token;
	int* output = new int[MAX_SIZE];
	int cnt = 0;
	Stack stack;
	for(int i = 0; i < length; i++) {
		/////
		if(isdigit(input[i])) {
			char* buf = new char[7];
			int j = 0;
			while(isdigit(input[i])) {
				buf[j] = input[i];
				j++;
				i++;
			}
			output[cnt] = atoi(buf);
			cnt++;
            delete[] buf;
		}
		token = input[i];
		if(token == '+' || token == '-' || token == '*' || token == '/') {
			if(token == '+') {
				token = -4;
			}
			if(token == '-') {
				token = -3;
			}
			if(token == '*') {
				token = -2;
			}
			if(token == '/') {
				token = -1;
			}
			if(!stack.isEmpty() && getPriority(token) <= getPriority(stack.top())) {
				output[cnt] = stack.pop();
				cnt++;
			}
			stack.push(token);
		}
		if(token == '(') {
			stack.push(token);
		}
		if(token == ')') {
			while( stack.top() != '(') {
				output[cnt] = stack.pop();
				cnt++;
			}
			stack.pop();
		}
	}
	while(!stack.isEmpty()) {
		output[cnt] = stack.pop();
		cnt++;
	}
	return count(output, cnt);
}


int main() {
	char* input = new char[MAX_SIZE];
	std::cin >> input;
    int result = toPostfix(input, MAX_SIZE);
	std::cout<<result;
	delete[] input;
	return 0;
}

