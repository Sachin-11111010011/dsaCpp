// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         int n=s.length();
//         if(n % 2 != 0){
//             return false;
//         }
//          stack<int> open;
//          stack<int> openClose;

//          for( int i=0; i< n; i++ ){
//             if(locked[i] == '0'){
//                 openClose.push(i);
//             }else if(s[i] == ')'){
//                 open.push(i);
//             } else if(s[i] == ')'){
//                 if(!open.empty()){
//                     open.pop();
//                 }else if (!openClose.empty()){
//                     openClose.pop();
//                 }else{
//                     return false;
//                 }
//             }
//          }
//          while(!open.empty() && !openClose.empty() && open.top() <openClose.top()){
//             open.pop();
//             openClose.pop();
//          }

//          return open.empty();
//     }
// };

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }

        stack<int> open, close;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                // Can be changed, add to a special stack
                open.push(i);
            } else if (s[i] == '(') {
                // It's a locked open parenthesis
                open.push(i);
            } else { // s[i] == ')'
                if (!open.empty()) {
                    open.pop();
                } else {
                    return false;
                }
            }
        }

        // At this point, handle any unbalanced open brackets
        // Check if they can be matched with changeable positions
        stack<int> leftoverOpen;
        while (!open.empty()) {
            if (locked[open.top()] == '0') {
                // Changeable '(' can be treated as ')'
                if (!leftoverOpen.empty()) {
                    leftoverOpen.pop();
                } else {
                    leftoverOpen.push(open.top());
                }
            } else {
                // Locked '(' goes to leftover stack
                leftoverOpen.push(open.top());
            }
            open.pop();
        }

        // If we still have unmatched '(' after processing, return false
        return leftoverOpen.size() % 2 == 0;
    }
};
