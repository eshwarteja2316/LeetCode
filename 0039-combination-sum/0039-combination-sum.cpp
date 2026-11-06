class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, 0, candidates, target, current, ans);
        return ans;
    }
    void solve(int index, int sum, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i=index;i<candidates.size();i++) {
            current.push_back(candidates[i]);
            solve(i, sum + candidates[i], candidates, target, current, ans);
            current.pop_back();
        }
    }
};