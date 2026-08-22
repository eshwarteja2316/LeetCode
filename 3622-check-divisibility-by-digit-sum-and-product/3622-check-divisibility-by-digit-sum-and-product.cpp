class Solution {
public:
    int get_digit(int n) {
        int temp = n;
        int product = 1;
        int sum = 0;
        while (temp != 0) {
            int digit = temp % 10;
            product *= digit;
            sum += digit;
            temp = temp / 10;
        }
        return product + sum;
    }
    bool checkDivisibility(int n) {
        int ans= get_digit(n);
        if (n % ans == 0) {
            return true;
            
        }
        return false;
    }
};