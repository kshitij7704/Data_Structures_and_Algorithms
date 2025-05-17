// Leetcode - 36

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Initinlizing vectors of unordered set to store the numbers
        vector<unordered_set<char>> row(9), col(9), box(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char c = board[i][j];
                //Checking only if the char is not a '.'
                if(c != '.'){
                    //Checking row
                    if(row[i].count(c))
                        return false;
                    row[i].insert(c);

                    //Checking col
                    if(col[j].count(c))
                        return false;
                    col[j].insert(c);

                    //Checking box
                    int boxInd = (i / 3) * 3 + (j / 3);
                    if(box[boxInd].count(c))
                        return false;
                    box[boxInd].insert(c);
                }
            }
        }
        return true;
    }
};
