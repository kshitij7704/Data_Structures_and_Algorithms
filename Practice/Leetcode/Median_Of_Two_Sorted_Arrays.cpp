// Leetcode - 4

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;
        for(int i : nums1){
           final.push_back(i);
        }
        for(int i : nums2){
            final.push_back(i);
            
        }
        sort(final.begin(), final.end());
        int n = final.size();
        if(n % 2 == 0){
            double sum = final[n/2] + final[(n/2) - 1];
            sum /= 2;
            return sum;
        }
        else{
            return final[n/2];
        }
    }
};
