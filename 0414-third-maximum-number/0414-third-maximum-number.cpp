class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long frist = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num:nums) {
            if (num == frist || num == second || num == third) {
                continue;
            }
            if (num > frist) {
                third = second;
                second = frist;
                frist = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }
        if (third == LLONG_MIN) {
            return frist;
        }
        return third;
    }
};