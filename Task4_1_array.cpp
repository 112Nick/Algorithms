//4_1: Очередь с динамическим зацикленным буфером

#include <iostream>


class Queue {
  private:    
    int* array;
    int capacity;
    int head;
    int tail;
    void realloc();
  public:
    Queue();
    ~Queue();
    int getCapacity();
    void pushBack(int n);
    int popFront();
};

Queue::Queue() {
    capacity = 10;
    head = 0;
    tail = 0;
    array = new int [capacity];    
}

int Queue::getCapacity() {
    return capacity;
}

void Queue::realloc() {
    int* newArray = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        newArray[i] = array[(head + i) % capacity]; 
    }   
    delete[] array;
    array = new int[2 * capacity];
    for (int i = 0; i < capacity; i++) {
        array[i] = newArray[i]; 
    }   
    head = 0;
    tail = capacity; 
    capacity*=2;
}

Queue::~Queue() {
    delete[] array;
    capacity = 0;
}

void Queue::pushBack(int n) {
    array[tail] = n;
    tail = (tail + 1) % capacity;
    if(tail == head) {
        realloc();
    } 
}

int Queue::popFront() {
    if (head != tail) {
        int val = array[head];
        head = (head + 1) % capacity;
        return val;
    }
    return -1;
}


int main() {
    int a,b,n;
    int buf = 0;
    Queue list;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a >> b;
        if(a == 2) {
            buf = list.popFront();
            if(buf != b) {
                std::cout << "NO";
                return 0;
            }
        }
        else if(a == 3) {
            list.pushBack(b);
        }
    }
    std::cout << "YES";
    return 0;
} 
