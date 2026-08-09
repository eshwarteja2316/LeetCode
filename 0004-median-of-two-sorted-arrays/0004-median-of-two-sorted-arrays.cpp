class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums(nums1.size()+nums2.size());
        double median;
        int i=0;
        int j=0;
        int k=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                nums[k]=nums1[i];
                i++;
            }
            else{
                nums[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<nums1.size()){
            nums[k]=nums1[i];
            k++;
            i++;
        }
        while(j<nums2.size()){
            nums[k]=nums2[j];
            k++;
            j++;
        }
        if(nums.size()%2==0){
            int a=nums.size()/2;
            int b=a-1;
            median=(nums[a]+nums[b])/(double)2;
        }
        else{
            int a=(nums.size()-1)/2;
            median=(double)nums[a];       
        }
        return median;
    }
};