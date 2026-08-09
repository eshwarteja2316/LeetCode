class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(k==0){
                if(mp[nums[i]]>1){
                    count++;
                }
                while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
                i++;
                continue;
            }
            int n=k+nums[i];
            if(mp.count(n)){
                count++;
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
            i++;
        }
        return count;
    }
};