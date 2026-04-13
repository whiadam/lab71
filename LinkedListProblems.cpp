// Problems 1-6: Singly Linked List recursive functions
// O(n) time, O(n) space for all unless noted
#include "LinkedList.h"
#include <vector>
using namespace std;

// Problem 1: Reverse singly linked list - O(n) time, O(n) space
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

void LinkedList::reverse() {
    head = reverseRecursive(head);
}

// Problem 2: Find middle node - O(n) time, O(n) space
Node* findMiddle(Node* slow, Node* fast) {
    if (!fast || !fast->next) return slow;
    return findMiddle(slow->next, fast->next->next);
}

Node* getMiddle(Node* head) {
    if (!head) return nullptr;
    return findMiddle(head, head);
}

// Problem 3: Check palindrome - O(n) time, O(n) space
void collectValues(Node* head, vector<int>& vals) {
    if (!head) return;
    vals.push_back(head->data);
    collectValues(head->next, vals);
}

bool checkPalin(vector<int>& vals, int left, int right) {
    if (left >= right) return true;
    if (vals[left] != vals[right]) return false;
    return checkPalin(vals, left + 1, right - 1);
}

bool isPalindrome(Node* head) {
    vector<int> vals;
    collectValues(head, vals);
    return checkPalin(vals, 0, vals.size() - 1);
}

// Problem 4: Count occurrences of x - O(n) time, O(n) space
int countOccurrences(Node* head, int x) {
    if (!head) return 0;
    return (head->data == x ? 1 : 0) + countOccurrences(head->next, x);
}

// Problem 5: Remove duplicates from sorted list - O(n) time, O(n) space
Node* removeDuplicates(Node* head) {
    if (!head || !head->next) return head;
    if (head->data == head->next->data) {
        Node* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return removeDuplicates(head);
    }
    head->next = removeDuplicates(head->next);
    return head;
}

// Problem 6: Insert at index k - O(n) time, O(n) space
Node* insertAtIndex(Node* head, int val, int k) {
    if (k == 0) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    if (!head) return nullptr;
    head->next = insertAtIndex(head->next, val, k - 1);
    return head;
}
