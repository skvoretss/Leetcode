class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l_mult = 1, r_mult = 1;
        vector<int> res(nums.size(), 1);
        for (size_t i = 0; i < nums.size(); ++i) {
            res[i] *= l_mult;
            l_mult *= nums[i]; 
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= r_mult;
            r_mult *= nums[i]; 
        }
        return res;
    }
};