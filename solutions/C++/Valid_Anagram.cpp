class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> vec(26, 0);
        for (size_t i = 0; i != s.size(); ++i){
            ++vec[static_cast<int>(s[i]-'a')];
            --vec[static_cast<int>(t[i]-'a')];
        }
        return vec.size() == count(vec.begin(), vec.end(), 0);
    }
};