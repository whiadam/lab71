// Problems 7-12: Doubly Linked List recursive functions
// O(n) time, O(n) space for all unless noted
#include "DoublyLinkedList.h"

// Problem 7: Reverse doubly linked list - O(n) time, O(n) space
DNode* reverseDLL(DNode* head) {
    if (!head || !head->next) {
        if (head) head->prev = nullptr;
        return head;
    }
    DNode* rest = reverseDLL(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = nullptr;
    return rest;
}

// Problem 8: Delete node by value x (first occurrence) - O(n) time, O(n) space
DNode* deleteByValue(DNode* head, int x) {
    if (!head) return nullptr;
    if (head->data == x) {
        DNode* tmp = head->next;
        if (tmp) tmp->prev = nullptr;
        delete head;
        return tmp;
    }
    head->next = deleteByValue(head->next, x);
    if (head->next) head->next->prev = head;
    return head;
}

// Problem 9: Find length recursively - O(n) time, O(n) space
int lengthDLL(DNode* head) {
    if (!head) return 0;
    return 1 + lengthDLL(head->next);
}

// Problem 10: Sum of all elements - O(n) time, O(n) space
int sumDLL(DNode* head) {
    if (!head) return 0;
    return head->data + sumDLL(head->next);
}

// Problem 11: Check if sorted ascending - O(n) time, O(n) space
bool isSortedDLL(DNode* head) {
    if (!head || !head->next) return true;
    if (head->data > head->next->data) return false;
    return isSortedDLL(head->next);
}

// Problem 12: Rotate by k positions - O(n) time, O(n) space
DNode* getTailDLL(DNode* head) {
    if (!head || !head->next) return head;
    return getTailDLL(head->next);
}

DNode* rotateDLL(DNode* head, int k) {
    if (!head || k == 0) return head;
    DNode* tail = getTailDLL(head);
    tail->next = head;
    head->prev = tail;
    DNode* newTail = head;
    for (int i = 0; i < k - 1; i++) newTail = newTail->next;
    DNode* newHead = newTail->next;
    newTail->next = nullptr;
    newHead->prev = nullptr;
    return newHead;
}
