// Leetcode - 1838

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0;
        int r=0;
        int ans=0;
        long long total = 0;
        for(int r=0;r<nums.size();r++){
            total = total + nums[r];
            if(k< (long long)nums[r]*(r-l+1) - total){
                total -= nums[l];
                l++;
            }
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};
