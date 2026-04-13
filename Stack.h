#pragma once
#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

class Stack {
public:
    SNode* top;
    Stack() : top(nullptr) {}
    void push(int val);
    int pop();
    bool isEmpty() { return top == nullptr; }
    int peek() { return top->data; }
};
