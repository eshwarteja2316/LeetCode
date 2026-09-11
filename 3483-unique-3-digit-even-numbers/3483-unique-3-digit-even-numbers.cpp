class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int x: digits) {
            freq[x]++;
        }
        int ans = 0;
        for (int a=1;a<=9;a++) {
            for (int b=0;b<=9;b++) {
                for (int c=0;c<=8;c+=2) {
                    int needA=1;
                    int needB=1;
                    int needC=1;

                    if (a==b) needA++;
                    if (a==c) needA++;
                    if (b==c) needB++;

                    if (freq[a] >= needA && freq[b] >= needB && freq[c] >= needC) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};