class Solution {
public:
    // 1 2 4 6 5 1
    // 0 1 0 0 1
    int nextGreaterElement(int n) {
        string s = "";
        
        int temp = n;
        while (temp > 0) {
            s += char('0' + temp % 10);
            temp /= 10;
        }

        reverse(s.begin(), s.end());
        
        // take an element which is smaller to its next element while traversing from right
    
        int idx = s.length() - 2;
        while (idx >= 0 && s[idx] >= s[idx + 1]) {
            idx--;
        }
        

        // if no such element found return -1
        if (idx < 0) return -1;


        // now after finding the pivot element swap it with minimum greater element
        int i = s.length() - 1;
        while (s[i] <= s[idx]) {
            i--;
        }
        
        // swap both of them
        swap(s[i], s[idx]);

        // reverse everything which is right to pivot element
        reverse(s.begin() + idx + 1, s.end());

        // convert ans string to long long
        long long ans = stoll(s);
        if (ans > INT_MAX) {
            return -1;
        }

        return (int)ans;
    }
};