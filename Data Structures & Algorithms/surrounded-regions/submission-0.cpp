class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,0));

        for(int i = 0; i< m; i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                visited[i][0] = true;
                mark(i,0,visited, board);
            }
        }
        for(int j = 0; j< n; j++){
            if(!visited[0][j] && board[0][j] == 'O'){
                visited[0][j] = true;
                mark(0,j,visited,board);
            }
        }
        for(int i = 0; i< m; i++){
            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                visited[i][n-1] = true;
                mark(i,n-1,visited, board);
            }
        }
        for(int j = 0; j< n; j++){
            if(!visited[m-1][j] && board[m-1][j] == 'O'){
                visited[m-1][j] = true;
                mark(m-1,j,visited,board);
            }
        }
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    visited[i][j] = true;
                    dfs(i,j,visited, board);
                }
            }
        }
        return;
    }
    void mark(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();

        if(board[r][c] == 'X'){
            return;
        }

        vector<int> dirn = {-1,0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nr = r + dirn[i];
            int nc = c + dirn[i+1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                visited[nr][nc] = true;
                mark(nr,nc, visited, board);
            }
        }
    }
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();

        if(board[r][c] == 'X'){
            return;
        }
        else board[r][c] = 'X';

        vector<int> dirn = {-1,0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nr = r + dirn[i];
            int nc = c + dirn[i+1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                visited[nr][nc] = true;
                dfs(nr,nc, visited, board);
            }
        }
    }
};