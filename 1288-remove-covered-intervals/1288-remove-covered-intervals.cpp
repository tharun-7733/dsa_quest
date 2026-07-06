class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] != b[0]) {
                return a[0] < b[0];
            } else{
                return a[1] > b[1];
            }
        });
        
        int count = 0, MaxEnd = 0;
        for(auto &i : intervals) {
            if(i[1] > MaxEnd) {
                MaxEnd = i[1];
                count++;
            }
        }
        return count;
    }
};