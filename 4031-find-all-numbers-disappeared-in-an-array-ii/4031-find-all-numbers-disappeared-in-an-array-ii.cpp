class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> miss;

        for (int i = lower; i <= upper; i++) {
            if (!st.count(i)) {
                miss.push_back(i);
            }
        }


        if (miss.empty()) return {};

        int start = miss[0];
        int prev = miss[0];
        
        vector<vector<int>> ans;

        for (int i = 1; i < miss.size(); i++) {
            if (miss[i] == prev + 1) {
                prev = miss[i];
            } else {
                ans.push_back({start, prev});
                start = prev = miss[i];
            }
        }

        ans.push_back({start, prev});

        return ans;
    }
};