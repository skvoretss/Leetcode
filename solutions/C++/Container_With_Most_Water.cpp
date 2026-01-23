class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, l = 0, r = height.size()-1;
        while (l < r) {
            int curArea = min(height[l], height[r]) * (r-l);
            res = max(res, curArea);
            if (height[l] > height[r]) --r;
            else ++l;
        }
        return res;
    }
};