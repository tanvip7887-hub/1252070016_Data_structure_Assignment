/*You are given a string containing only parentheses characters: '(', ')', '{', '}', '[', and ']'. Your task is to check whether the parentheses 
  are balanced or not.
    A string is considered balanced if:
    1.	Every opening bracket has a corresponding closing bracket of the same type
    2.	Brackets are closed in the correct order.	
*/

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string containing parentheses: ";
    cin >> s;
    if(isBalanced(s))
        cout << "The parentheses are balanced\n";
    else
        cout << "The parentheses are not balanced\n";
    return 0;
}
