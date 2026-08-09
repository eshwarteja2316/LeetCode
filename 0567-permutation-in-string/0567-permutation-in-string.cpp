class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for (char c : s1) {
            mp2[c]++;
        }
        int i = 0;
        int j = 0;
        while (j < s2.size()) {
            mp1[s2[j]]++;
            if (j - i + 1 == s1.size()) {
                if(mp1==mp2){
                    return true;
                }
                else {
                    mp1[s2[i]]--;
                    if (mp1[s2[i]] == 0) {
                        mp1.erase(s2[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};