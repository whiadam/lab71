#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedLinkedList.h"
using namespace std;

int main() {
    cout << "Lab 7.1 - Recursive ADTs" << endl;

    LinkedList ll;
    ll.insert(1); ll.insert(2); ll.insert(3); ll.insert(4);
    cout << "Original: "; ll.print();
    ll.reverse();
    cout << "Reversed: "; ll.print();

    SortedLinkedList sll;
    sll.insert(1); sll.insert(3); sll.insert(5); sll.insert(7);
    cout << "Sorted list: "; sll.print();
    Node* found = sll.search(5);
    cout << "Search 5: " << (found ? "found" : "not found") << endl;

    Stack s;
    s.push(3); s.push(1); s.push(4); s.push(1); s.push(5);
    cout << "Stack top before sort: " << s.peek() << endl;

    Queue q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4);
    cout << "Queue size: " << q.size() << endl;

    return 0;
}
