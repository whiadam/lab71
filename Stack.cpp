#include "Stack.h"

void Stack::push(int val) {
    SNode* newNode = new SNode(val);
    newNode->next = top;
    top = newNode;
}

int Stack::pop() {
    if (!top) return -1;
    int val = top->data;
    SNode* tmp = top;
    top = top->next;
    delete tmp;
    return val;
}
