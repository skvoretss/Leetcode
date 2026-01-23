class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, l = 0, r = nums.size()-1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == nums[mid]) return mid;
            else if (nums[mid] >= nums[0]) {
                if (target > nums[mid]) ++l;
                else {
                    if (target >= nums[0]) --r;
                    else ++l;
                }
            }
            else if (nums[mid] < nums[0]){
                if (target < nums[mid]) --r;
                else {
                    if (target < nums[0]) ++l;
                    else --r;
                }
            }
        }
        return -1;
    }
};