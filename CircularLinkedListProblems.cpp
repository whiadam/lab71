// Problems 13-17: Circular Linked List recursive functions
// O(n) time, O(n) space for all unless noted
#include "CircularLinkedList.h"

// Problem 13: Count cycle length - O(n) time, O(n) space
int cycleLength(CNode* cur, CNode* head, bool started) {
    if (started && cur == head) return 0;
    return 1 + cycleLength(cur->next, head, true);
}

int countCycleLength(CNode* head) {
    if (!head) return 0;
    return cycleLength(head->next, head, false);
}

// Problem 14: Search for value x - O(n) time, O(n) space
bool searchCircular(CNode* cur, CNode* head, int x, bool started) {
    if (started && cur == head) return false;
    if (cur->data == x) return true;
    return searchCircular(cur->next, head, x, true);
}

bool searchValue(CNode* head, int x) {
    if (!head) return false;
    return searchCircular(head, head, x, false);
}

// Problem 15: Delete head and point last to new head - O(n) time, O(n) space
CNode* findLastNode(CNode* cur, CNode* head) {
    if (cur->next == head) return cur;
    return findLastNode(cur->next, head);
}

CNode* deleteHead(CNode* head) {
    if (!head) return nullptr;
    if (head->next == head) { delete head; return nullptr; }
    CNode* last = findLastNode(head, head);
    CNode* newHead = head->next;
    last->next = newHead;
    delete head;
    return newHead;
}

// Problem 16: Find maximum element - O(n) time, O(n) space
int findMax(CNode* cur, CNode* head, bool started, int maxVal) {
    if (started && cur == head) return maxVal;
    int currMax = cur->data > maxVal ? cur->data : maxVal;
    return findMax(cur->next, head, true, currMax);
}

int getMax(CNode* head) {
    if (!head) return -1;
    return findMax(head->next, head, false, head->data);
}

// Problem 17: Check if two circular lists are identical - O(n) time, O(n) space
bool checkIdentical(CNode* c1, CNode* h1, CNode* c2, CNode* h2, bool started) {
    if (started && c1 == h1 && c2 == h2) return true;
    if (started && (c1 == h1 || c2 == h2)) return false;
    if (c1->data != c2->data) return false;
    return checkIdentical(c1->next, h1, c2->next, h2, true);
}

bool areIdentical(CNode* h1, CNode* h2) {
    if (!h1 && !h2) return true;
    if (!h1 || !h2) return false;
    return checkIdentical(h1, h1, h2, h2, false);
}
