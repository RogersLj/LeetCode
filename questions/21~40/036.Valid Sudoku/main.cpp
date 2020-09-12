class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9), col(9), cell(9);

        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                if(board[i][j] < '1' || board[i][j] > '9') return false;
                int num = board[i][j] - '0';

                if((row[i] & (1 << num)) || (col[j] & (1 << num)) || (cell[(i / 3) * 3 + (j / 3)] & (1 << num))) return false;

                row[i] |= (1 << num);
                col[j] |= (1 << num);
                cell[(i / 3) * 3 + (j / 3)] |= (1 << num);

            }

        return true;
    }
};
