class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] % 2 == 0) {
                even++;
            }
        }
        vector<int>ans(nums.size());
        for (int i=0;i<nums.size();i++) {
            if (i<even) {
                ans[i]=0;
            }
            else {
                ans[i]=1;
            }
        }
        return ans;
    }
};