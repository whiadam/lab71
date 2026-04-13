#include "CircularLinkedList.h"

void CircularLinkedList::insert(int val) {
    CNode* newNode = new CNode(val);
    if (!head) { head = newNode; head->next = head; return; }
    CNode* cur = head;
    while (cur->next != head) cur = cur->next;
    cur->next = newNode;
    newNode->next = head;
}

void CircularLinkedList::print() {
    if (!head) return;
    CNode* cur = head;
    do { cout << cur->data << " "; cur = cur->next; } while (cur != head);
    cout << endl;
}
