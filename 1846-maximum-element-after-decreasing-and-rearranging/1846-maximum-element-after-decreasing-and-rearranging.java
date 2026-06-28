class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        boolean flag = true, one = true;
        int ans = 0;

        if(arr[0] != 1) {
            arr[0] = 1;
        }

        if(n == 1) return 1;

        for(int i = 1; i < n; i++) {
            if((arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            ans = Math.max(ans, arr[i]);
        }
        return ans;
    }
}