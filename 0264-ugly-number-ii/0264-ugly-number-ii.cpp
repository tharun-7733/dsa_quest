class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);

        ugly[0] = 1;
        int i_2 = 0, i_3 = 0, i_5 = 0;

        for (int i = 1; i < n; i++) {
            long long next2 = ugly[i_2] * 2;
            long long next3 = ugly[i_3] * 3;
            long long next5 = ugly[i_5] * 5;

            ugly[i] = min({next2, next3, next5});

            if (ugly[i] == next2) {
                i_2++;
            }

            if (ugly[i] == next3) {
                i_3++;
            }

            if (ugly[i] == next5) {
                i_5++;
            }
        }

        return ugly.back();
    }
};