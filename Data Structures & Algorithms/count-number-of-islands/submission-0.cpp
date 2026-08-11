class Solution {

private:
    int dir[5] = {-1, 0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<char>> & grid){
        if(grid[i][j]=='0') return;
        grid[i][j]= '0';

        int m = grid.size();
        int n = grid[0].size();

        for(int k = 0;k<4;++k){
            int dirx, diry;
            dirx = dir[k];
            diry = dir[k+1];

            if(i + dirx < m && i+ dirx>=0 && j+diry <n && j+diry>=0 && grid[i+dirx][j+diry] == '1') dfs(i+dirx, j+diry, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j = 0;j<grid[0].size();++j){
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};