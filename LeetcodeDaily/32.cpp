class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // Custom comparator for priority queue (max-heap by delta)
        auto delta = [](pair<double, int>& a, pair<double, int>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(delta)> pq(delta);

        // Initialize the priority queue with current delta values
        for (int i = 0; i < n; i++) {
            double currentPR = (double)classes[i][0] / classes[i][1];
            double newPR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double gain = newPR - currentPR;
            pq.push({gain, i});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto curr = pq.top();
            pq.pop();

            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;

            // Recalculate and push updated delta for the same class
            double currentPR = (double)classes[idx][0] / classes[idx][1];
            double newPR = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            double gain = newPR - currentPR;
            pq.push({gain, idx});
        }

        // Calculate the final average pass ratio
        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += (double)classes[i][0] / classes[i][1];
        }
        return result / n;
    }
};
