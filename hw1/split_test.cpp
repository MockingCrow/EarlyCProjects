#include "split.h"
#include <iostream>

using namespace std;

struct Node* head = NULL;
struct Node* odds = NULL;
struct Node* evens = NULL;

// make linked list by appending to the beginning
void append(int num) {
    struct Node* addNode = (struct Node*)malloc(sizeof(struct Node));
    addNode->value = num;
    addNode->next = head;
    head = addNode;
}

// print linked list front to end
void printList(Node*& beginning) {
    struct Node* traverse;
    traverse = beginning;
    while (traverse != NULL) {
        cout << traverse->value << " ";
        traverse = traverse->next;
    }
}

int main() {
    // populate original list
    append(9);
    append(4);
    append(6);
    append(10);
    append(12);
    append (13);
    append(0);
    append(71);

    split(head, odds, evens);
    cout << "Evens: ";
    printList(evens);
    cout << "Odds: ";
    printList(odds);
    cout << endl;

    return 0;
}