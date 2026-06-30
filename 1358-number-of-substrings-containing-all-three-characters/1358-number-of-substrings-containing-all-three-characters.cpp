class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0;

        int subStr = 0;
        unordered_map<char, int> mp;
        while(right < n) {
            mp[s[right]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                subStr += n - right;
                mp[s[left]]--;
                left++;
            }

            right++;
        }

        return subStr;
    }
};