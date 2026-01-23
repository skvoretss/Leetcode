class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cur_set;
        int max_len = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (cur_set.find(s[i]) == cur_set.end()) {
                cur_set.insert(s[i]);
            }
            else {
                max_len = max(max_len, r-l);
                while (true) {
                    if (s[l] != s[r]) {
                        cur_set.erase(s[l]);
                        ++l;
                    }
                    else {
                        ++l;
                        break;
                    }
                }
            }
            ++r;
        }
        max_len = max(max_len, r-l);
        return max_len;
    }
};