#include "SortedLinkedList.h"

void SortedLinkedList::insert(int val) {
    Node* newNode = new Node(val);
    if (!head || head->data >= val) { newNode->next = head; head = newNode; return; }
    Node* cur = head;
    while (cur->next && cur->next->data < val) cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
}

void SortedLinkedList::print() {
    Node* cur = head;
    while (cur) { cout << cur->data << " "; cur = cur->next; }
    cout << endl;
}
