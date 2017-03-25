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
		char* array;
		int size;
		int cur;
	public:
		Stack();
		void push(char c);
		char pop();
		char top();
		bool isEmpty();
};

Stack::Stack() {
	array = new char[MAX_SIZE];
	size = 0;
}

char Stack::pop() {
	char val;
	val = array[size - 1];
	size--;
	return val;
}

char Stack::top() {
	char val;
	val = array[size - 1];
	return val;
}


void Stack::push(char c) {
	array[size] = c;
	size++;
}

bool Stack::isEmpty() {
	if(size == 0)
		return true;
	return false;	
}

int getPriority(char operand) {
	if(operand == '*')
		return 4;
	if(operand == '/')
		return 4;
	if(operand == '+')
		return 3;
	if(operand == '-')
		return 3;	
	return 0;
	
}

char* toPostfix(char* input, int length) {
	char token;
	char* output = new char[MAX_SIZE];
	int cnt = 0;
	Stack stack;
	for(int i = 0; i < length; i++) {
		token = input[i];
		if(isdigit(token)) {
			output[cnt] = token;
			cnt++;
		}
		if(token == '+' || token == '-' || token == '*' || token == '/') {
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
	return output;
}

/*string str = "hdge626jsbs7362";
 
vector<string> v;
 
string buf = "";
for (int i = 0; i < str.size(); ++i) {
  if (isdigit(str[i])) {
    buf.push_back(str[i]);
  } 
  else if (buf.size() > 0) {
    v.push_back(buf);
    buf = "";
  }
}
*/

int main() {
	char* input = new char[MAX_SIZE];
	std::cin >> input;
	std::cout << toPostfix(input, MAX_SIZE);
	return 0;
}

