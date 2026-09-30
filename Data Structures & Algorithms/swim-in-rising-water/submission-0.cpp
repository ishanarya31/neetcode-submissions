class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dirn = {-1,0,1,0,-1};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,0));

        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            if(cur.second.first == n-1 && cur.second.second == n-1) return cur.first;
            for(int i = 0; i < 4; i++){
                int nr = cur.second.first + dirn[i];
                int nc = cur.second.second + dirn[i+1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    pq.push({max(cur.first,grid[nr][nc]), {nr, nc}});
                }
            }
        }
        return -1;
    }
};