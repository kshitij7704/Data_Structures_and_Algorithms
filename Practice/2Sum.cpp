// Leetcode - 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int need = target - curr;
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[curr] = i;
        }
        return {};
    }
};
