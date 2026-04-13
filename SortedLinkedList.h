#pragma once
#include "LinkedList.h"

class SortedLinkedList {
public:
    Node* head;
    SortedLinkedList() : head(nullptr) {}
    void insert(int val);
    void print();
    Node* search(int target);
};
