class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        int left = 0, right = 0;
        int n = s.length();

        int count = 0;
        string num = "";
        for(int i = 2; i <= 9; i++) {
            int left = 0, right = i - 1;

            while(right < 9) {    
                int number = stoi(s.substr(left, i));
                if (number >= low and number <= high) {
                    ans.push_back(number);
                }
                left++;  
                right++;
            }
        }
        return ans;
    }
};