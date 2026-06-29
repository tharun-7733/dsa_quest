class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for(auto &c : patterns) {
            if(word.contains(c)) cnt++;
        }
        return cnt;
    }
};