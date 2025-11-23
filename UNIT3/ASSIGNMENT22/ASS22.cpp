/*Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the operations step by step.	*/

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
