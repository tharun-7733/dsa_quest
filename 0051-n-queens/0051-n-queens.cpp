class Solution {
public:
    void solve(int col, int n, vector<string> &board ,vector<vector<string>> &res, vector<int> &upperDiagnol, vector<int> &lowerDiagnol, vector<int> &leftRow){
        if(col == n){
            res.push_back(board);
            return ;
        }

        for(int i = 0;i < n;i++){
            if(leftRow[i] == 0 && upperDiagnol[(n-1) + col - i] == 0 && lowerDiagnol[i + col] == 0){
                board[i][col] = 'Q';
                leftRow[i] = 1;
                upperDiagnol[(n-1) + col - i] = 1;
                lowerDiagnol[i+col] = 1;
                solve(col + 1, n, board, res, upperDiagnol, lowerDiagnol, leftRow);
                board[i][col] = '.';
                leftRow[i] = 0;
                upperDiagnol[(n-1) + col - i] = 0;
                lowerDiagnol[i + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n);
        for(int i = 0;i < n; i++){
            board[i] = s;
        }

        vector<int> lowerDiagnol(2*n-1, 0);
        vector<int> upperDiagnol(2*n-1, 0);
        vector<int> leftRow(2*n-1, 0);
        solve(0, n, board, res, upperDiagnol, lowerDiagnol, leftRow);
        return res;
    }
};