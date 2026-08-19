class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < reservedSeats.size(); i++) {
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        int count = 0;
        for (auto &p : mp) {
            bool middle = true;
            bool left = true;
            bool right = true;
            for (auto &i : p.second) {
                if (i == 4 || i == 5 || i == 6 || i == 7) middle = false;
                if (i == 2 || i == 3 || i == 4 || i == 5) left = false;
                if (i == 6 || i == 7 || i == 8 || i == 9) right = false;
            }

            if (left && right) count += 2;
            else if (middle || left || right) count += 1;
        }

        count += (n - mp.size()) * 2;

        return count;
    }
};