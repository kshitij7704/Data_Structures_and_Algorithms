// Leetcode - 22

class Solution {
public:
    vector<string> res;

    void getPara(string str, int n, int openN, int closeN){
        if(openN == n && closeN == n){
            res.push_back(str);
            return;
        }
        if(openN < n){
            getPara(str + '(', n, openN + 1, closeN);
        }
        if(closeN < openN){
            getPara(str + ')', n, openN, closeN + 1);
        }
    }

    vector<string> generateParenthesis(int n){
        string str = "";
        getPara(str, n, 0, 0);
        return res;   
    }
};
