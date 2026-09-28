class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>> graph;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(n, false);
        int cost = 0, count = 0;

        pq.push({0, 0});  // {dist, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;
            cost += d;
            count++;

            if (count == n) return cost;

            for (auto& [v, w] : graph[u]) {
                if (!vis[v]) pq.push({w, v});
            }
        }

        return cost;
    }
};