// Leetcode - 20

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> umap;
        umap[']'] = '[';
        umap['}'] = '{';
        umap[')'] = '(';
        for(char c : s){
            if(umap.count(c)){
                if(!st.empty() && st.top() == umap[c])
                    st.pop();
                else
                    return false;
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
