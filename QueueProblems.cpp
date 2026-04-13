// Problems 22-25: Queue recursive functions
// O(n) time, O(n) space for all
#include "Queue.h"
#include <string>
using namespace std;

// Problem 22: Reverse a queue - O(n) time, O(n) space
void reverseQueue(Queue& q) {
    if (q.isEmpty()) return;
    int val = q.dequeue();
    reverseQueue(q);
    q.enqueue(val);
}

// Problem 23: Priority queue insertion (insert in sorted order) - O(n) time, O(n) space
void insertPriority(Queue& q, int val) {
    if (q.isEmpty() || q.front->data >= val) {
        Queue tmp;
        tmp.enqueue(val);
        while (!q.isEmpty()) tmp.enqueue(q.dequeue());
        q.front = tmp.front;
        q.rear = tmp.rear;
        return;
    }
    int front = q.dequeue();
    insertPriority(q, val);
    Queue tmp;
    tmp.enqueue(front);
    while (!q.isEmpty()) tmp.enqueue(q.dequeue());
    q.front = tmp.front;
    q.rear = tmp.rear;
}

// Problem 24: Generate binary numbers up to n - O(n) time, O(n) space
void generateBinary(Queue& q, int n, int count) {
    if (count > n) return;
    string front = to_string(q.front->data);
    // reuse queue to store strings via a separate approach
    // simplified: print binary numbers using queue BFS
    q.dequeue();
    generateBinary(q, n, count + 1);
}

void printBinaryNumbers(int n) {
    if (n <= 0) return;
    Queue q;
    q.enqueue(1);
    auto helper = [&](auto& self, int count) -> void {
        if (count > n) return;
        int front = q.dequeue();
        cout << front << endl;
        q.enqueue(front * 10);
        q.enqueue(front * 10 + 1);
        self(self, count + 1);
    };
    helper(helper, 1);
}

// Problem 25: Interleave first half with second half - O(n) time, O(n) space
void interleaveHelper(Queue& first, Queue& second, Queue& result) {
    if (first.isEmpty() && second.isEmpty()) return;
    if (!first.isEmpty()) result.enqueue(first.dequeue());
    if (!second.isEmpty()) result.enqueue(second.dequeue());
    interleaveHelper(first, second, result);
}

void interleaveQueue(Queue& q) {
    int n = q.size();
    int half = n / 2;
    Queue first, second;
    for (int i = 0; i < half; i++) first.enqueue(q.dequeue());
    while (!q.isEmpty()) second.enqueue(q.dequeue());
    Queue result;
    interleaveHelper(first, second, result);
    q.front = result.front;
    q.rear = result.rear;
}
