#include <iostream>

using namespace std;
struct List {
    int value;
    List *next;
};

int main() {
    List *head = new List;
    List *list = head;
    for (int i = 1; i < 6; i++) {
        list->value = i;
        if (i == 5) list->next = NULL;
        else {
            list->next = new List;
            list = list->next;
        }
    }
    list = head;
    for (int i = 1; i < 6; i++) {
        cout << list->value;
        list = list->next;
    }
    return 0;
}