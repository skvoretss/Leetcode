class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int& elem: nums){
            int cur_size = us.size();
            us.insert(elem);
            if (us.size() == cur_size) return true;
        }
        return false;
    }
};