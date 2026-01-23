class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int lmax = 0, rmax = 0, p1 = 0, p2 = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int tmp = p1;
            p1 = max(p1, p2 + nums[i]);
            p2 = tmp;
        }
        lmax = p1;
        p1 = 0;
        p2 = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            int tmp = p1;
            p1 = max(p1, p2 + nums[i]);
            p2 = tmp;
        }
        rmax = p1;

        return max(lmax, rmax);
    }
};