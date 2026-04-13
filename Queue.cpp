#include "Queue.h"

void Queue::enqueue(int val) {
    QNode* newNode = new QNode(val);
    if (!rear) { front = rear = newNode; return; }
    rear->next = newNode;
    rear = newNode;
}

int Queue::dequeue() {
    if (!front) return -1;
    int val = front->data;
    QNode* tmp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete tmp;
    return val;
}

int Queue::size() {
    int count = 0;
    QNode* cur = front;
    while (cur) { count++; cur = cur->next; }
    return count;
}
