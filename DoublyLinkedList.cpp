#include "DoublyLinkedList.h"

void DoublyLinkedList::insert(int val) {
    DNode* newNode = new DNode(val);
    if (!head) { head = newNode; return; }
    DNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
    newNode->prev = cur;
}

void DoublyLinkedList::print() {
    DNode* cur = head;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << endl;
}
