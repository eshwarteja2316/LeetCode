class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int rem = num % k;
            newDp[rem] = 1;

            for (int i=0;i<k;i++) {
                int newRem = (i*rem) % k;
                newDp[newRem] += dp[i];
            }
            for (int i=0;i<k;i++) {
                ans[i] += newDp[i];
            }
            dp = newDp;
        }
        return ans;
    }
};