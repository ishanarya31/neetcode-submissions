class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i =0; i< 9; i++){
            unordered_set<char> row;
            for(int j = 0 ; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(row.count(board[i][j])) return false;
                row.insert(board[i][j]);
            }
        }

        for(int i =0; i< 9; i++){
            unordered_set<char> col;
            for(int j = 0 ; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(col.count(board[j][i])) return false;
                col.insert(board[j][i]);
            }
        }
        
        for(int m =0; m < 9; m += 3){
            for(int n = 0; n< 9 ; n+= 3){
                unordered_set<char> sq;
                for(int j = 0 ; j < 3; j++){
                    for(int k = 0 ; k < 3; k++){
                        if(board[j+m][k+n] == '.') continue;
                        if(sq.count(board[j+m][k+n])) return false;
                        sq.insert(board[j+m][k+n]); 
                    }
                }
            }            
        }
        return true;
    }
};
