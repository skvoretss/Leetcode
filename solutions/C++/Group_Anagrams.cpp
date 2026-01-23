class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> um;
        vector<vector<string>> res;
        for (int i = 0; i != strs.size(); ++i){
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            if (um.find(sortedString) != um.end())
                res[um[sortedString]].push_back(strs[i]);
            else{
                um[sortedString] = res.size();
                res.push_back({strs[i]});
            }

        }
        return res;
    }
};