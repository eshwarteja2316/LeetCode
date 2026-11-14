class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i=0;i<26;i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a'+i});
            }
        }
        string ans = "";
        pair<int, char> prev ={0,'#'};
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ans += curr.second;
            curr.first--;

            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = curr;
        }
        if (ans.size() != s.size()) {
            return "";
        }
        return ans;
    }
};