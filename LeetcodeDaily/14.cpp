class Solution {
public:
    #define P pair<int, int>
    unordered_map<int, vector<P>> adj;

    // Dijkstra's algorithm to compute shortest path from node 0 to node n-1
    int dijkstra(int n) {
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1) {
                return result[n - 1];
            }

            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int wt = p.second;

                if (d + wt < result[adjNode]) {
                    result[adjNode] = d + wt;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result[n - 1];
    }

    // Main function to process queries
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initialize the base graph with edges {i, i+1, 1}
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back({i + 1, 1});
        }

        vector<int> result;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new edge from the query
            adj[u].push_back({v, 1});

            // Compute the shortest distance from node 0 to node n-1
            int d = dijkstra(n);
            result.push_back(d);
        }

        return result;
    }
};
