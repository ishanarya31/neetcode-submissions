class Solution {
public:
    int area = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MIN;
        for(int i = 0; i< m; i++){
            for(int j = 0 ; j< n; j++){
                area = 0;
                if(grid[i][j] == 1) dfs(i, j, grid);
                res = max(res, area);
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(grid[r][c] == 0) return;
        if(grid[r][c] == 1){
            grid[r][c] = 0;
            area++;
        }
        vector<int> dirn = {-1,0,1,0,-1};
        for(int i = 0; i< 4; i++){
            int nr = r + dirn[i];
            int nc = c + dirn[i+1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                dfs(nr,nc,grid);
            }
        }
    }
};