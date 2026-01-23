class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (nums.size() < 2) return nums.size();

        int res_max = 0;
        int cur_max = 0;
        unordered_set<int> un_s;
        for (size_t i = 0; i != nums.size(); ++i)
            un_s.insert(nums[i]);

        for (size_t i = 0; i != nums.size(); ++i)
            if (un_s.find(nums[i]+1) == un_s.end()) {
                while (un_s.find(nums[i]-cur_max) != un_s.end()){
                    un_s.erase(nums[i]-cur_max);
                    ++cur_max;
                }
                res_max = max(res_max, cur_max);
                cur_max = 0;
            }
        return res_max;
    }
};