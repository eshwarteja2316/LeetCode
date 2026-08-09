class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int>maxi(nums.size());
        maxi[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            maxi[i]=max(nums[i],maxi[i+1]);
        }
        int sum=0;
        for(int i=0;i<nums.size()-k;i++){
            sum=max(sum,nums[i]+maxi[k+i]);
        }
        return sum;
    }
};