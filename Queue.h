#pragma once
#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int val) : data(val), next(nullptr) {}
};

class Queue {
public:
    QNode* front;
    QNode* rear;
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int val);
    int dequeue();
    bool isEmpty() { return front == nullptr; }
    int size();
};
