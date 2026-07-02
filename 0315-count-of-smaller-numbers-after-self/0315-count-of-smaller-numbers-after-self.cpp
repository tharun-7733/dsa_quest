class Solution {
public:
    vector<pair<int, int>> mp;
    int n;
    void CountSmall(int l, vector<int>& ans, int mid, int r) {
        int i = l, j = mid + 1;
        vector<pair<int, int>> temp;

        while(i <= mid && j <= r) {
            if(mp[i].first > mp[j].first) {
                ans[mp[i].second] += r - j + 1;
                temp.push_back(mp[i]);
                i++;
            } else{
                temp.push_back(mp[j]);
                j++;
            }
        }

        while(i <= mid) temp.push_back(mp[i++]);

        while(j <= r) temp.push_back(mp[j++]);

        for(int k = l; k <= r; k++) {
            mp[k] = temp[k - l];
        }
    }
    void merge(vector<int>& ans, int l, int r) {
        if(l >= r) return ;

        int m = l + (r - l) / 2;
        merge(ans, l, m);
        merge(ans, m + 1, r);
        CountSmall(l, ans, m, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();

        for (int i = 0; i < n; i++) {
            mp.push_back({nums[i], i});
        }

        vector<int> ans(n, 0);
        
        merge(ans, 0, n - 1);
        return ans;
    }
};