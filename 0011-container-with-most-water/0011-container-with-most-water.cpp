class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int curr=min(height[i],height[j])*(j-i);
            maxWater=max(maxWater,curr);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxWater;
    }
};