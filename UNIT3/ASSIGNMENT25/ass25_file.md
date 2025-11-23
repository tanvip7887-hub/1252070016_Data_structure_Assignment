
ASSIGNMENT 25
==============

AIM
----

You are given a postfix expression (also known as Reverse Polish Notation) consisting of single-digit operands and binary operators (+, -, *, /).
Your task is to evaluate the expression using stack and return its result.*/

THEORY
-------

Postfix expression evaluation is done using a stack. In postfix form, operators come after their operands, so the expression is processed from left to right.
Whenever an operand (digit) appears, it is pushed into the stack.
Whenever an operator appears, the top two values are popped from the stack, the operation is performed, and the result is pushed back.
This process continues until the entire expression is scanned.
In the end, the final value remaining in the stack is the result of the postfix expression.


PROGRAM
--------

```CPP
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix_TRP(string expr_TRP) {
    stack<int> st_TRP;
    for(char c_TRP : expr_TRP) {
        if(c_TRP >= '0' && c_TRP <= '9') {
            st_TRP.push(c_TRP - '0');
        } else {
            int b_TRP = st_TRP.top(); st_TRP.pop();
            int a_TRP = st_TRP.top(); st_TRP.pop();
            switch(c_TRP) {
                case '+': st_TRP.push(a_TRP + b_TRP); break;
                case '-': st_TRP.push(a_TRP - b_TRP); break;
                case '*': st_TRP.push(a_TRP * b_TRP); break;
                case '/': st_TRP.push(a_TRP / b_TRP); break;
            }
        }
    }
    return st_TRP.top();
}

int main() {
    string expr_TRP;
    cout << "Enter postfix expression: ";
    cin >> expr_TRP;
    int result_TRP = evaluatePostfix_TRP(expr_TRP);
    cout << "Result: " << result_TRP << endl;
    return 0;
}
```

OUTPUT
-------

Enter postfix expression: 52+83-*4/
Result: 3



