#include <iostream>
#include <stack>

bool isBalanced(const std::string& expr) {
    std::stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    std::string expr = "{[()]}";
    if (isBalanced(expr)) {
        std::cout << "Balanced\n";
    } else {
        std::cout << "Not Balanced\n";
    }
    return 0;
}
