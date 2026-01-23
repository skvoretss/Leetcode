class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    --l;
                    ++r;
                }
                else {
                    if (res.size() < r-l-1) {
                        res = s.substr(l+1, r-l-1);
                    }
                    break;
                }
            }
            if (res.size() < r-l-1) {
                res = s.substr(l+1, r-l-1);
            }
            l = i, r = i+1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    --l;
                    ++r;
                }
                else {
                    if (res.size() < r-l-1) {
                        res = s.substr(l+1, r-l-1);
                    }
                    break;
                }
            }
            if (res.size() < r-l-1) {
                res = s.substr(l+1, r-l-1);
            }
        }
        return res;
    }
};