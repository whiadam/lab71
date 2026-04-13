#pragma once
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() : head(nullptr) {}
    void insert(int val);
    void print();
};
