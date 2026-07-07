class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s = to_string(n);
        string num = "";


        for(char &c : s) {
            if(c != '0') {
                num += c;
                sum += c - '0';
            }
        }

        long long ans = (num.empty()) ? 0 : stoll(num);
        return (long long)ans * sum;
    }
};