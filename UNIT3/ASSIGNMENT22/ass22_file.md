
ASSIGNMENT 22
==============

AIM - Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the operations step by step.

THEORY
------

Infix expressions are written in the normal human-readable form, where operators appear between operands.
Example: a - b * c - d / e + f

Computers prefer postfix (Reverse Polish Notation) because it removes the need for brackets and operator precedence rules.
Example postfix form of the above expression is: abc*-de/-f+

To convert infix to postfix, we use a stack to temporarily hold operators.
Rules used:
    Operands (a–z, A–Z, 0–9) are directly added to the postfix expression.
    *Operators (+, -, , /) are pushed on the stack according to precedence.

* and / have higher precedence than + and -.

If the incoming operator has lower or equal precedence, we pop from stack and add to postfix.
Parentheses are handled by pushing ( onto the stack and popping until ) is found.
At the end, all remaining operators in the stack are popped and added to postfix.
This method ensures the postfix expression is generated correctly without using brackets.


PROGRAM
--------

```CPP
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence_TRP(char op_TRP) {
    if(op_TRP == '+' || op_TRP == '-') return 1;
    if(op_TRP == '*' || op_TRP == '/') return 2;
    return 0;
}

bool isOperator_TRP(char c_TRP) {
    return c_TRP == '+' || c_TRP == '-' || c_TRP == '*' || c_TRP == '/';
}

void infixToPostfix_TRP(string infix_TRP) {
    stack<char> s_TRP;
    string postfix_TRP = "";
    cout << "Step by step conversion:\n";
    for(char c_TRP : infix_TRP) {
        if((c_TRP >= 'a' && c_TRP <= 'z') || (c_TRP >= 'A' && c_TRP <= 'Z')) {
            postfix_TRP += c_TRP;
            cout << "Add operand " << c_TRP << " to postfix: " << postfix_TRP << endl;
        } else if(c_TRP == '(') {
            s_TRP.push(c_TRP);
            cout << "Push '(' onto stack\n";
        } else if(c_TRP == ')') {
            while(!s_TRP.empty() && s_TRP.top() != '(') {
                postfix_TRP += s_TRP.top();
                cout << "Pop " << s_TRP.top() << " from stack and add to postfix: " << postfix_TRP << endl;
                s_TRP.pop();
            }
            s_TRP.pop();
            cout << "Pop '(' from stack\n";
        } else if(isOperator_TRP(c_TRP)) {
            while(!s_TRP.empty() && precedence_TRP(s_TRP.top()) >= precedence_TRP(c_TRP)) {
                postfix_TRP += s_TRP.top();
                cout << "Pop " << s_TRP.top() << " from stack and add to postfix: " << postfix_TRP << endl;
                s_TRP.pop();
            }
            s_TRP.push(c_TRP);
            cout << "Push operator " << c_TRP << " onto stack\n";
        }
    }
    while(!s_TRP.empty()) {
        postfix_TRP += s_TRP.top();
        cout << "Pop " << s_TRP.top() << " from stack and add to postfix: " << postfix_TRP << endl;
        s_TRP.pop();
    }
    cout << "Final Postfix Expression: " << postfix_TRP << endl;
}

int main() {
    string infix_TRP;
    cout << "Enter infix expression: ";
    cin >> infix_TRP;
    infixToPostfix_TRP(infix_TRP);
    return 0;
}
```

OUTPUT
-------

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>g++ ASS22.cpp

C:\Users\USER\OneDrive\Desktop\VS_DS_CPP>a.exe

Enter infix expression: a-b*c-d/e+f
Step by step conversion:
Add operand a to postfix: a
Push operator - onto stack
Add operand b to postfix: ab
Push operator * onto stack
Add operand c to postfix: abc
Pop * from stack and add to postfix: abc*
Pop - from stack and add to postfix: abc*-
Push operator - onto stack
Add operand d to postfix: abc*-d
Push operator / onto stack
Add operand e to postfix: abc*-de
Pop / from stack and add to postfix: abc*-de/
Pop - from stack and add to postfix: abc*-de/-
Push operator + onto stack
Add operand f to postfix: abc*-de/-f
Pop + from stack and add to postfix: abc*-de/-f+
Final Postfix Expression: abc*-de/-f+
