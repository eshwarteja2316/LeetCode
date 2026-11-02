class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort (deck.begin(), deck.end());

        int n = deck.size();

        queue<int> q;

        for (int i=0;i<n;i++) {
            q.push(i);
        }
        vector<int> ans(n);
        for(int card : deck) {
            int index = q.front();
            q.pop();

            ans[index] = card;

            if (!q.empty()) {
                int next = q.front();
                q.pop();

                q.push(next);
            }
        }
        return ans;
    }
};