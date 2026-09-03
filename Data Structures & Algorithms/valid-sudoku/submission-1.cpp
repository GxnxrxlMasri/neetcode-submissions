class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int n = board[i][j];
                if (n != '.') {
                    if (rows[i].contains(n)) {
                        return false;
                    } else {
                        rows[i].insert(n);
                    }
                    if (cols[j].contains(n)) {
                        return false;
                    } else {
                        cols[j].insert(n);
                    }
                    int squareIndex = (i / 3) * 3 + (j / 3);
                    if (squares[squareIndex].contains(n)) {
                        return false;
                    } else {
                        squares[squareIndex].insert(n);
                    }
                }
            }
        }
        return true;
    }
};
