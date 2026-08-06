class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n;
        long long product = 1;

        while (temp > 0) {
            int last = temp % 10;
            product *= last;
            temp /= 10;
        }

        int ans = 0;
        if (product % t == 0) {
            ans = n;
        } else {
            while (n++) {
                long long prod = 1;
                int temp1 = n;
                while (temp1 > 0) {
                    int last = temp1 % 10;
                    prod *= last;
                    temp1 /= 10;
                }

                if (prod % t == 0) {
                    ans = n;
                    break;
                }
            }
        }
        return ans;
    }
};