class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> mp;

        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(mp[s[left]]);
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};