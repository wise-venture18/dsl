//Q.) In any language program mostly syntax error occurs due to unbalancing 
// delimiter such as (),{},[]. Write C++ program using stack to check whether 
// given expression is well parenthesized or not. 

#include <iostream>
#include <stack>
using namespace std;

// Function to check if two characters are matching pairs
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// Function to check if an expression is well-parenthesized
bool isWellParenthesized(string expr) {
    stack<char> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If the character is an opening delimiter, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If the character is a closing delimiter
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty or not matching
            if (st.empty() || !isMatchingPair(st.top(), ch)) {
                return false;
            }
            // Pop the matching opening delimiter
            st.pop();
        }
    }

    // If the stack is empty, the expression is well-parenthesized
    return st.empty();
}

// Main function
int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized.\n";
    } else {
        cout << "The expression is not well-parenthesized.\n";
    }

    return 0;
}
