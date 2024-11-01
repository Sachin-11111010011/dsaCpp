#include <iostream>
#include <stack>
using namespace std;

#define N 4

// Helper function to check if a person knows another person
bool knows(int M[N][N], int a, int b) {
    return M[a][b] == 1;
}

// Function to find the celebrity
int findCelebrity(int M[N][N], int n) {
    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Determine the candidate for celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        // If A knows B, then A cannot be a celebrity, push B
        if (knows(M, A, B)) {
            s.push(B);
        }
        // If A does not know B, then B cannot be a celebrity, push A
        else {
            s.push(A);
        }
    }

    // Step 3: Verify the candidate
    int candidate = s.top();
    s.pop();

    // Check if the candidate is a celebrity
    for (int i = 0; i < n; i++) {
        // Candidate should not know anyone else and everyone should know the candidate
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate))) {
            return -1;
        }
    }

    return candidate;
}

int main() {
    int M[N][N] = { {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0} };

    int result = findCelebrity(M, N);
    if (result == -1) {
        cout << "There is no celebrity in the party.\n";
    } else {
        cout << "The celebrity is person " << result << ".\n";
    }

    return 0;
}
