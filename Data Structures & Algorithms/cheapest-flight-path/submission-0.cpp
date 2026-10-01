class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        int f = flights.size();

        vector<vector<int>> graph(n, vector<int>(n, -1));

        vector<int> price(n, INT_MAX);
        price[src] = 0;

        for (int i = 0; i < f; i++) {
            graph[flights[i][0]][flights[i][1]] = flights[i][2];
        }

        for (int t = 0; t <= k; t++) { // k+1 rounds = at most k+1 edges
            vector<int> tmp = price;   // write to a copy
            for (int i = 0; i < n; i++) {
                if (price[i] == INT_MAX)
                    continue; // unreachable, skip
                for (int j = 0; j < n; j++) {
                    if (i != j && graph[i][j] != -1) {
                        tmp[j] = min(tmp[j], price[i] + graph[i][j]); // read from old price
                    }
                }
            }
            price = tmp;
        }

        return (price[dst] == INT_MAX) ? -1 : price[dst];
    }
};