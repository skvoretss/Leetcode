class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        unordered_map<char, int> umRow;
        for (int i = 0; i != 9; ++i){
            for (int j = 0; j != 9; ++j){
                if ((board[i][j] >= '0') && (board[i][j] <= '9')){
                    ++umRow[board[i][j]];
                    if (umRow[board[i][j]] > 1)
                        return false;
                }
            }
            umRow.clear();
        }

        // column
        unordered_map<char, int> umColumn;
        for (int i = 0; i != 9; ++i){
            for (int j = 0; j != 9; ++j){
                if ((board[j][i] >= '0') && (board[j][i] <= '9')){
                    ++umColumn[board[j][i]];
                    if (umColumn[board[j][i]] > 1)
                        return false;
                }
            }
            umColumn.clear();
        }

        // square
        unordered_map<char, int> umSquare;
        for (int curRow = 0; curRow < 3; ++curRow){
            for (int curColumn = 0; curColumn < 3; ++curColumn){
                for (int i = 3*curRow; i < 3*curRow+3; ++i){
                    for (int j = 3*curColumn; j < 3*curColumn+3; ++j){
                        if ((board[i][j] >= '0') && (board[i][j] <= '9')){
                            ++umSquare[board[i][j]];
                            if (umSquare[board[i][j]] > 1)
                                return false;
                        }
                    } 
                }
                umSquare.clear();
            }
        }
        return true;
    }
};