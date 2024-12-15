 
 
// Implement C++ program for expression conversion as infix to postfix and its 
// evaluation using stack based on given conditions: 
// 1. Operands and operator, both must be single character. 
// 2. Input Postfix expression must be in a desired format. 
// 3. Only '+', '-', '*' and '/ ' operators are expected. 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check precedence of operators
int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        // If operand, add to result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            result += s[i];
        }
        // If opening parenthesis, push to stack
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // If closing parenthesis, pop and append until '(' is encountered
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();  // Remove the '('
            }
        }
        // If operator, check precedence and pop if necessary
        else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    
    // Pop any remaining operators in the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

// Main function
int main() {
    string infix;

    cout << "Enter a valid infix expression: ";
    cin >> infix;

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
