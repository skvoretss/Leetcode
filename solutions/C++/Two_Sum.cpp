class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for (int i = 0; i != nums.size(); ++i) {
            s[nums[i]] = i;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (s.contains(target - nums[i]) && i != s[target - nums[i]]) {
                return {i, s[target - nums[i]]};
            }
        }
        return {};
    }
};