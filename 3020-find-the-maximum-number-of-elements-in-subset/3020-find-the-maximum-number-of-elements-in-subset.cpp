class Solution {
public:
    const long long MOD = 1e10;
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = 0;

        if(mp[1] % 2 != 0) ans = mp[1];
        else ans = mp[1] - 1;

        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for(int p : st) {
            long long current = p;

            if(current == 1) continue;

            int len = 0;

            while(mp[current] >= 2) {
                len += 2;

                current = (current * current) % MOD;
            }

            if(mp[current] >= 1) len++;
            else len--;

            ans = max(ans, len);
        }
        return ans;
    }
};