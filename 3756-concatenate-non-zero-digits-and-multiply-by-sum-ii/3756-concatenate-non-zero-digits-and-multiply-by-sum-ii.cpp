class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int len = s.length();
        const int MOD = 1e9 + 7;

        vector<long long> pow10(len + 1, 1), prefix_sum(len + 1, 0), prefixCnt(len + 1, 0), prefix_d(len + 1, 0);
        vector<int> ans;


        // digit prefix sum
        string t = "";

        for(int i = 0; i < len; i++) {
            prefix_d[i + 1] = prefix_d[i] + (s[i] != '0');
            prefix_sum[i + 1] = prefix_sum[i] + (s[i] - '0');

            if(s[i] != '0') t.push_back(s[i]);
        }
        int n = t.size(); 

        // Powers
        pow10.assign(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> prefixVal(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefixVal[i + 1] = (prefixVal[i] * 10 + (t[i] - '0')) % MOD;
        }

        // X
        for (auto &i: queries) {
            int l = i[0];
            int r = i[1];

            int L = prefix_d[l];
            int R = prefix_d[r + 1];

            long long value = 0;
            if(L < R) {
                value = (prefixVal[R] - (prefixVal[L] * pow10[R - L]) % MOD + MOD) % MOD;
            }

            long long sum = prefix_sum[r + 1] - prefix_sum[l];

            ans.push_back((int)((value * sum) % MOD));
        }
        
        return ans;
    }
};