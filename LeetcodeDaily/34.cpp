#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); // To count the frequency of each character
        
        // Count frequency of characters in the string
        for (char &ch : s) {
            count[ch - 'a']++;
        }

        // Max heap to store characters in lexicographically descending order
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({char('a' + i), count[i]});
            }
        }

        string result;
        while (!pq.empty()) {
            // Get the most frequent character
            auto [ch, freq] = pq.top();
            pq.pop();

            // Add the character up to repeatLimit times
            int use = min(freq, repeatLimit);
            result.append(use, ch);

            freq -= use; // Reduce the remaining frequency

            // If this character still remains and there is another option
            if (freq > 0 && !pq.empty()) {
                // Get the next character
                auto [nextCh, nextFreq] = pq.top();
                pq.pop();

                // Append one occurrence of the next character
                result.push_back(nextCh);
                nextFreq--;

                // Push both back into the heap if they still have remaining frequency
                if (nextFreq > 0) {
                    pq.push({nextCh, nextFreq});
                }
                pq.push({ch, freq}); // Push the current character back for further use
            }
        }
        return result;
    }
};
