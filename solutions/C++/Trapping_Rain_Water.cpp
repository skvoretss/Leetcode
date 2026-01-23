class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.size() == 1) return res;
        
        vector<int> lMax(height.size(), 0);
        int rMax = 0;

        for (size_t i = 1; i != height.size(); ++i)
            lMax[i] = max(height[i-1], lMax[i-1]);
        
        for (int i = static_cast<int>(height.size()) - 2; i >= 0; --i) {
            rMax = max(height[i+1], rMax);
            res += max(0, min(lMax[i], rMax) - height[i]);
        }

        return res;
    }
};