// Leetcode - 37

class Solution {
public:
    bool isValidBoard(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            // Column checking
            if(board[i][col] == c) 
                return false;

            // Row checking
            if(board[row][i] == c) 
                return false;

            // 3 by 3 box checking
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                // If empty cell is found
                if(board[i][j] == '.'){

                    // Check placing all 1-9 numbers
                    for(char c='1';c<='9';c++){
                        if(isValidBoard(board, i, j, c)){
                            board[i][j] = c; // Placing a number

                            if(solve(board)) // Recursive call
                                return true;

                            else
                                board[i][j] = '.'; // Backtracking step
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        return true; // Solved
    }

    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};
