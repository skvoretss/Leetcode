class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right){
            while ((left <= s.size() -1) && (!(isalpha(s[left]) || (isdigit(s[left])))))
                ++left;
            while ((right >= 0) && (!(isalpha(s[right]) || (isdigit(s[right])))))
                --right;
            
            if ((left <= s.size() - 1) && (right >= 0))
                if (tolower(s[left]) != tolower(s[right]))
                    return false;
            ++left;
            --right;
        }
        return true;
    }
};