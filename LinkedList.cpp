#include "LinkedList.h"

void LinkedList::insert(int val) {
    Node* newNode = new Node(val);
    if (!head) { head = newNode; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
}

void LinkedList::print() {
    Node* cur = head;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << endl;
}
