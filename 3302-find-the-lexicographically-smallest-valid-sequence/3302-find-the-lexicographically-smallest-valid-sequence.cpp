class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<int> last(m, -1);
        vector<int> ans;


        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // atmost one 1 tolerance level to change the char in word1
        bool canSkip = true;
        j = 0;

        for (int i = 0; i < n; i++) {
            if (j == m) break;

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (canSkip && (j == m - 1 || i < last[j + 1])) {
                ans.push_back(i);
                canSkip = false;
                j++;
            }
        }

        if (j == m) {
            return ans;
        }
        
        return {};
    }
};