// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i =0; i< 9; i++){
//             unordered_set<char> row;
//             for(int j = 0 ; j < 9; j++){
//                 if(board[i][j] == '.') continue;
//                 if(row.count(board[i][j])) return false;
//                 row.insert(board[i][j]);
//             }
//         }

//         for(int i =0; i< 9; i++){
//             unordered_set<char> col;
//             for(int j = 0 ; j < 9; j++){
//                 if(board[j][i] == '.') continue;
//                 if(col.count(board[j][i])) return false;
//                 col.insert(board[j][i]);
//             }
//         }
        
//         for(int m =0; m < 9; m += 3){
//             for(int n = 0; n< 9 ; n+= 3){
//                 unordered_set<char> sq;
//                 for(int j = 0 ; j < 3; j++){
//                     for(int k = 0 ; k < 3; k++){
//                         if(board[j+m][k+n] == '.') continue;
//                         if(sq.count(board[j+m][k+n])) return false;
//                         sq.insert(board[j+m][k+n]); 
//                     }
//                 }
//             }            
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                char cur = board[i][j];

                if (cur == '.') continue;

                int square = (i / 3) * 3 + (j / 3);

                if (rows[i].contains(cur) ||
                    cols[j].contains(cur) ||
                    squares[square].contains(cur))
                    {
                        return false;
                    }

                rows[i].insert(cur);
                cols[j].insert(cur);
                squares[square].insert(cur);
            }
        }

        return true;
    }
};

