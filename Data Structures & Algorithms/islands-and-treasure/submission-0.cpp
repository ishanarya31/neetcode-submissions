class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> srcs;
        for(int i =0;i < m;i++){
            for(int j = 0 ; j< n; j++){
                if(grid[i][j] == 0){
                    srcs.push_back({i,j}); 
                }
            }
        }
        bfs(srcs, grid);
        return;
    }
    void bfs(vector<pair<int,int>>& srcs, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,0));
        vector<int> dirn = {-1,0,1,0,-1};
        queue<pair<int,int>>q;

        for(auto &[r,c] : srcs){
            q.push({r,c});
            visited[r][c] = 1;
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(int i = 0; i< 4;i++){
                int dr = dirn[i];
                int dc = dirn[i+1];

                int nr = curr.first + dr;
                int nc = curr.second + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != -1 && !visited[nr][nc]){
                    grid[nr][nc] = 1 + grid[curr.first][curr.second];
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return;
    }
};
