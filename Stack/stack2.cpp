#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;
    istringstream tokens(expression);
    string token;
    
    while (tokens >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {  // Handle negative numbers
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
    }
    return s.top();
}

int main() {
    string expression = "2 3 + 5 *";
    cout << "Result: " << evaluatePostfix(expression) << endl;  // Output: 25
    return 0;
}
