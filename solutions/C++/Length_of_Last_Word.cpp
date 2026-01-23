class Solution {
public:
    int lengthOfLastWord(string s) {
        int save_len = 0;
        int cnt_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') { 
                ++cnt_len;
            }
            else if (cnt_len) {
                save_len = cnt_len;
                cnt_len = 0;
            }
        }
        if (cnt_len) save_len = cnt_len;
        
        return save_len;
    }
};