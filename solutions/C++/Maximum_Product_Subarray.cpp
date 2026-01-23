class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1, max_prod = INT_MIN;
        for (size_t i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            max_prod = max(max_prod, prod);
            if (!prod) prod = 1;
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            prod *= nums[i];
            max_prod = max(max_prod, prod);
            if (!prod) prod = 1;
        }
        return max_prod;
    }
};