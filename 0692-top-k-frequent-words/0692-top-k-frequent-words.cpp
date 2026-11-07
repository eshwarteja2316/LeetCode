class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>freq;
        for (string word : words) {
            freq[word]++;
        }
        auto cmp = [](pair<string, int>& a,pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<string, int>, 
        vector<pair<string, int>>,
        decltype(cmp)
        >pq(cmp);

        for (auto& it : freq) {
            pq.push({it.first, it.second});
        } 
        vector<string> ans;

        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};