class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted) {
            return 0;
        }
        int n = s.size();

        if (n == 2) {
            return -1;
        }
        char mn = sorted[0];
        char mx = sorted[n-1];

        if (s[0] == mn || s[n-1] == mx) {
            return 1;
        } 
        for (int i=1;i<n-1;i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        return 3;
    }
};