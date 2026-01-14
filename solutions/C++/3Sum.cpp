class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int prefix = nums[0];
        int cur_min = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prefix += nums[i];
            res = max(res, max(prefix, prefix-cur_min));
            if (cur_min > prefix) {
                cur_min = prefix;
            }
        }
        return res;
    }
};