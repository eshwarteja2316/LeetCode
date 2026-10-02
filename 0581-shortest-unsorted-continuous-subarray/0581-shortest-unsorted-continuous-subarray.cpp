class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while (left < n && nums[left] == sorted[left]) {
            left++;
        }
        while (right >= 0 && nums[right] == sorted[right]) {
            right--;
        }
        if (left >= right) {
            return 0;
        }
        return right - left + 1;
    }
};