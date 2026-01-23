class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (string cur_str: strs) {
            if (cur_str.size() < res.size()) {
                res = cur_str;
            }
        }
        for (string cur_str: strs) {
            for (int i = 0; i < min(cur_str.size(), res.size()); ++i) {
                if (res[i] != cur_str[i]) {
                    res.erase(i, res.size()-i);
                    break;
                }
            }
        }
        return res;
    }
};