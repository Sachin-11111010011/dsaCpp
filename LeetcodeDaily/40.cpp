class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) return 1; // If there's only one node, there's one component
        
        int ans = 0;
        vector<vector<int>> g(n);
        vector<int> in(n, 0); // Degree of each node

        // Build the graph and compute node degrees
        for (auto edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            g[node1].push_back(node2);
            g[node2].push_back(node1);
            in[node1]++;
            in[node2]++;
        }

        vector<long long> longValues(values.begin(), values.end()); // Use long long for sum calculations

        // Start with leaf nodes
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 1) q.push(i); // Push leaf nodes into the queue
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            in[curr]--; // Mark the node as processed
            
            // Compute carry value: if the node's value is not divisible by k, carry it forward
            long long carry = (longValues[curr] % k == 0) ? 0 : longValues[curr];
            if (carry == 0) ans++; // Increment answer if the current component is divisible by k

            for (int ng : g[curr]) {
                if (in[ng] > 0) { // Process unvisited neighbors
                    in[ng]--; // Decrement the degree of the neighbor
                    longValues[ng] += carry; // Add the carry value to the neighbor
                    if (in[ng] == 1) q.push(ng); // Push the neighbor into the queue if it becomes a leaf
                }
            }
        }
        return ans;
    }
};
