class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<string> res;
        string cur_range = "";
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1] - 1 && !cur_range.size()) {
                cur_range += to_string(nums[i]) + "->";
            }
            else if (!cur_range.size()) res.push_back(to_string(nums[i]));
            else if (nums[i] != nums[i+1] - 1 && cur_range.size()){
                res.push_back(cur_range + to_string(nums[i]));
                cur_range = "";
            }
        }
        cur_range += to_string(nums[nums.size()-1]);
        res.push_back(cur_range);
        return res;
    }
};