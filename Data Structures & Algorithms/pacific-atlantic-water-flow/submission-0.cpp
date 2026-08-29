class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<int> dirn = {-1,0,1,0,-1};
        vector<vector<int>> res;

        vector<vector<bool>> visited(m,vector<bool>(n,0));
        queue<pair<int , int>> q;
        for(int i = 0 ; i< m; i++){
            q.push({i,0});
            visited[i][0] = true;
        }
        for(int i = 1; i< n; i++){
            q.push({0,i});
            visited[0][i] = true;
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = curr.first + dirn[i];
                int nc = curr.second + dirn[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                    if(heights[curr.first][curr.second] <= heights[nr][nc]){
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                    }
                }
            }
        }

        vector<vector<bool>> visited2(m,vector<bool>(n,0));

        for(int i = 0; i < m; i++){
            q.push({i,n-1});
            visited2[i][n-1] = true;
        }

        for(int i = 0; i< n-1; i++){
            q.push({m-1,i});
            visited2[m-1][i] = true;
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(int i =0; i < 4; i++){
                int nr = curr.first + dirn[i];
                int nc = curr.second + dirn[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited2[nr][nc]){
                    if(heights[curr.first][curr.second] <= heights[nr][nc]){
                        q.push({nr,nc});
                        visited2[nr][nc] = true;
                    }
                }
            }
        }

        for(int i =0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(visited[i][j] && visited2[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};