class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, local_min = nums[0], global_min = nums[0], mid = INT_MAX;
        while (l <= r) {
            mid = (l + r) / 2;
            global_min = min(global_min, nums[mid]);
            if (nums[mid] >= local_min) ++l;
            else --r;
        }
        return global_min;
    }
};