class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size()-1;
        while ((left < right) && (right >= 0) && (left < nums.size())){
            if (nums[left]+nums[right] == target)
                return {left+1, right+1};
            else if (nums[left]+nums[right] > target)
                --right;
            else
                ++left;
        }
        return {};
    }
};