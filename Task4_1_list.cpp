//4_1: Очередь с динамическим зацикленным буфером

#include <iostream>

struct Node {
   int value;
   Node* next;
   Node* prev;
};

class List {
  private:    
    Node* head;
    Node* tail;
    int size;  
  public:
    List();
    ~List();
    int getSize();
    void pushBack(int n);
    int popFront();
};

List::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

int List::getSize() {
    return size;
}

List::~List() {
    while(head != tail) {
        Node* cur = head;
        head = head->next;
        delete cur;
    }
    delete tail;
    size = 0;
}

void List::pushBack(int n) {
    Node* element = new Node;
    if(size == 0) {
        element->next = element;
        element->prev = element;
        this->head = element;
        this->tail = element;
    }
    else {
        element->next = this->head;
        this->head->prev = element;
        element->prev = this->tail;
        this->tail->next = element;
        this->tail = element;        
    }
    element->value = n;	
    size++;
}

int List::popFront() {
    if(size == 0) {
        return -1;
    }
    int val;
    Node* cur = this->head;
    val = cur->value;
    if(size == 1) {
        delete cur;
        head = NULL;
        tail = NULL;
        size--; 
        return val;
    }
    this->head = cur->next;
    delete cur;
    this->head->prev = this->tail;
    this->tail->next = this->head;
    size--;
    return val;
}

int main() {
    int a,b,n;
    int buf=0;
    List list;
    std::cin>>n;
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
