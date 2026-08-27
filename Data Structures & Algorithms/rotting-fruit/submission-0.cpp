class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = -1;
        queue<pair<int,int>> q;
        vector<int> dirn = {-1,0,1,0,-1};
        int fresh = 0;
        for(int i =0; i< m; i++){
            for(int j =0; j< n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int time = -1;
        while(!q.empty()){
            int sz = q.size();

            time++;
            for(int i=0; i< sz; i++){
                auto curr = q.front();
                q.pop();

                for(int i =0;i < 4; i++){
                    int nr = curr.first + dirn[i];
                    int nc = curr.second + dirn[i+1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && fresh > 0){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            } 
        }

        return fresh == 0 ? time : -1;
    }
};