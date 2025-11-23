/*You are given a postfix expression (also known as Reverse Polish Notation) consisting of single-digit operands and binary operators (+, -, *, /).
 Your task is to evaluate the expression using stack and return its result.*/

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
