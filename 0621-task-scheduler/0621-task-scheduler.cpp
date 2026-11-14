class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            while (cycle > 0 && !pq.empty()) {
                int count = pq.top();
                pq.pop();
                count--;
                if (count > 0) {
                    temp.push_back(count);
                }
                ans++;
                cycle--;
            }
            for (int count : temp) {
                pq.push(count);
            }
            if (!pq.empty()) {
                ans += cycle;
            }
        }
        return ans;
    }
};