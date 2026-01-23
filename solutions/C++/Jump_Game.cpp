class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReached = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReached) return false;
            int maxjump = min(i+nums[i], static_cast<int>(nums.size())-1);
            maxReached = max(maxReached, maxjump);
        }
        return true;
    }
};