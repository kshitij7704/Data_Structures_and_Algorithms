// leetcode - 6

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> matrix(numRows, vector<char>(n, ' '));
        bool down = true;
        for(int i=0,j=0,k=0;k<n;k++){
            matrix[i][j] = s[k];
            if(down){
                if(i == numRows - 1){
                    down = false;
                    i--;
                    j++;
                } 
                else 
                    i++;
            } 
            else{
                if(i == 0){
                    down = true;
                    i++;
                } 
                else {
                    i--;
                    j++;
                }
            }
        }
        string ans = "";
        for(int row=0;row<numRows;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col] != ' '){
                    ans += matrix[row][col];
                }
            }
        }
        return ans;
    }
};
