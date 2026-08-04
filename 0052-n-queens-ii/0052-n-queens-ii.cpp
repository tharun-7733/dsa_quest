class Solution {
public:
    vector<int> upperDiagnol;
    vector<int> lowerDiagnol;
    vector<int> leftRow;
    int solve(int col, int n) {
        int cnt = 0;
        if (col == n) return 1;

        for (int i = 0; i < n; i++) {
            if (leftRow[i] == 0 && 
                upperDiagnol[(n - 1) + col - i] == 0 && 
                lowerDiagnol[col + i] == 0) 
                {
                    leftRow[i] = 1;
                    upperDiagnol[(n - 1) + col - i] = 1;
                    lowerDiagnol[col + i] = 1;

                    cnt += solve(col + 1, n);

                    leftRow[i] = 0;
                    upperDiagnol[(n - 1) + col - i] = 0;
                    lowerDiagnol[col + i] = 0;
                }
        }

        return cnt;
    }
    int totalNQueens(int n) {
        this -> upperDiagnol.resize(2 * n - 1, 0);
        this -> lowerDiagnol.resize(2 * n - 1, 0);
        this -> leftRow.resize(2 * n - 1, 0);
        
        return solve(0, n);
    }
};