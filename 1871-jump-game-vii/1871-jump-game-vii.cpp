class Solution {
public:
    // int dp[1000001];
    // bool solve(int idx, const string &s, int minJump, int maxJump) {
    //     // int n = s.length();

    //     // if(idx >= n) return false;
    //     // if(idx == n - 1) return true;

    //     // if(dp[idx] != -1) return dp[idx];

    //     // for(int i = idx + minJump; i <= min(idx + maxJump, n - 1); i++) {
    //     //     if(s[i] == '0') {
    //     //         if (solve(i, s, minJump, maxJump)) {
    //     //             return dp[idx] = true;
    //     //         }
    //     //     }
    //     // }

    //     // return dp[idx] = false;
    // }

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<bool> dp(n, false);
        
        if(s[0] == '1' || s[n - 1] == '1') return false;

        int reachable = 0;
        dp[0] = true;
        for(int i = 1; i < n; i++) {
            // add new
            if(i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }
            // remove old element
            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachable--;
            }

            dp[i] = (reachable > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};