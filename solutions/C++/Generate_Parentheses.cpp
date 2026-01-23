class Solution {
public:
    void getParentheses(vector<string>& res, int n, string cur_s, int cntLeft, int cntRight) {
        if (cntRight == n) {
            res.push_back(cur_s);
            return;
        }

        if (cntLeft == n)
            getParentheses(res, n, cur_s+")", cntLeft, cntRight+1);
        else if (cntLeft == cntRight)
            getParentheses(res, n, cur_s+"(", cntLeft+1, cntRight);
        else {
            getParentheses(res, n, cur_s+")", cntLeft, cntRight+1);
            getParentheses(res, n, cur_s+"(", cntLeft+1, cntRight);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur_s = "(";
        int cntLeft = 1, cntRight = 0;
        getParentheses(res, n, cur_s, cntLeft, cntRight);
        return res;
    }
};