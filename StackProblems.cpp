// Problems 18-21: Stack recursive functions
// O(n) time, O(n) space for all
#include "Stack.h"
#include <string>
using namespace std;

// Problem 18: Sort a stack recursively - O(n^2) time, O(n) space
void insertSorted(Stack& s, int val) {
    if (s.isEmpty() || s.peek() <= val) { s.push(val); return; }
    int top = s.pop();
    insertSorted(s, val);
    s.push(top);
}

void sortStack(Stack& s) {
    if (s.isEmpty()) return;
    int top = s.pop();
    sortStack(s);
    insertSorted(s, top);
}

// Problem 19: Reverse a stack recursively - O(n^2) time, O(n) space
void insertAtBottom(Stack& s, int val) {
    if (s.isEmpty()) { s.push(val); return; }
    int top = s.pop();
    insertAtBottom(s, val);
    s.push(top);
}

void reverseStack(Stack& s) {
    if (s.isEmpty()) return;
    int top = s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}

// Problem 20: Evaluate postfix expression - O(n) time, O(n) space
int evalPostfix(const string& expr, int i, Stack& s) {
    if (i == (int)expr.size()) return s.pop();
    char c = expr[i];
    if (isdigit(c)) {
        s.push(c - '0');
    } else if (c != ' ') {
        int b = s.pop();
        int a = s.pop();
        if (c == '+') s.push(a + b);
        else if (c == '-') s.push(a - b);
        else if (c == '*') s.push(a * b);
        else if (c == '/') s.push(a / b);
    }
    return evalPostfix(expr, i + 1, s);
}

int evaluatePostfix(const string& expr) {
    Stack s;
    return evalPostfix(expr, 0, s);
}

// Problem 21: Check balanced parentheses - O(n) time, O(n) space
bool checkBalanced(const string& s, int i, Stack& st) {
    if (i == (int)s.size()) return st.isEmpty();
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        st.push(s[i]);
    } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        if (st.isEmpty()) return false;
        int top = st.pop();
        if ((s[i] == ')' && top != '(') ||
            (s[i] == ']' && top != '[') ||
            (s[i] == '}' && top != '{')) return false;
    }
    return checkBalanced(s, i + 1, st);
}

bool isBalanced(const string& expr) {
    Stack st;
    return checkBalanced(expr, 0, st);
}
