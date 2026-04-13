// Problems 26-30: Sorted Linked List recursive functions
#include "SortedLinkedList.h"

// Problem 26: Binary search on sorted linked list - O(n log n) time, O(log n) space
Node* getMiddlePtr(Node* start, Node* end) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start->next;
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* binarySearchRecursive(Node* start, Node* end, int target) {
    if (start == end) return nullptr;
    Node* mid = getMiddlePtr(start, end);
    if (!mid) return nullptr;
    if (mid->data == target) return mid;
    if (mid->data > target) return binarySearchRecursive(start, mid, target);
    return binarySearchRecursive(mid->next, end, target);
}

Node* SortedLinkedList::search(int target) {
    return binarySearchRecursive(head, nullptr, target);
}

// Problem 27: QuickSort on linked list - O(n log n) avg, O(n^2) worst time, O(log n) space
Node* getTail(Node* cur) {
    while (cur && cur->next) cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = head, *tail = pivot;
    while (cur != end) {
        if (cur->data < pivot->data) {
            if (!(*newHead)) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (!(*newHead)) (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

Node* quickSortHelper(Node* head, Node* end) {
    if (!head || head == end) return head;
    Node *newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSortHelper(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortHelper(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node*& head) {
    head = quickSortHelper(head, getTail(head));
}

// Problem 28: Merge sort on linked list - O(n log n) time, O(log n) space
Node* splitList(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    Node* mid = slow->next;
    slow->next = nullptr;
    return mid;
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) { a->next = merge(a->next, b); return a; }
    b->next = merge(a, b->next);
    return b;
}

void mergeSort(Node*& head) {
    if (!head || !head->next) return;
    Node* mid = splitList(head);
    mergeSort(head);
    mergeSort(mid);
    head = merge(head, mid);
}

// Problem 29: Check if list A is a subset of sorted list B - O(n+m) time, O(n+m) space
bool isSubset(Node* a, Node* b) {
    if (!a) return true;
    if (!b) return false;
    if (a->data == b->data) return isSubset(a->next, b->next);
    if (a->data > b->data) return isSubset(a, b->next);
    return false;
}

// Problem 30: Insertion sort on unsorted linked list recursively - O(n^2) time, O(n) space
Node* sortedInsert(Node* sorted, Node* newNode) {
    if (!sorted || newNode->data <= sorted->data) {
        newNode->next = sorted;
        return newNode;
    }
    sorted->next = sortedInsert(sorted->next, newNode);
    return sorted;
}

Node* insertionSort(Node* head) {
    if (!head) return nullptr;
    Node* rest = insertionSort(head->next);
    head->next = nullptr;
    return sortedInsert(rest, head);
}
