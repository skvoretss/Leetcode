class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        int min_row = 0, min_col = 0, max_row = n - 1, max_col = m - 1, cur_way = 1;
        // 1 - right; 2 - down; 3 - left; 4 - up
        vector<int> res;
        while (res.size() < m*n) {
            if (cur_way == 1) {
                for (int i = min_col; i <= max_col; ++i) res.push_back(matrix[min_row][i]);
                ++min_row;
                cur_way = 2;
            }
            else if (cur_way == 2) {
                for (int i = min_row; i <= max_row; ++i) res.push_back(matrix[i][max_col]);
                --max_col;
                cur_way = 3;
            }
            else if (cur_way == 3) {
                for (int i = max_col; i >= min_col; --i) res.push_back(matrix[max_row][i]);
                --max_row;
                cur_way = 4;
            }
            else if (cur_way == 4) {
                for (int i = max_row; i >= min_row; --i) res.push_back(matrix[i][min_col]);
                ++min_col;
                cur_way = 1;
            }
        }
        return res;
    }
};