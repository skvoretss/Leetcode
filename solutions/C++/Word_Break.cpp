class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        int max_len = -1;
        for (string& s: wordDict) {
            us.insert(s);
            max_len = max(max_len, static_cast<int>(s.size()));
        }
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= max(i-max_len-1, 0); --j) {
                if (us.contains(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[dp.size()-1];
    }
};