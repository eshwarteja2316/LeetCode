class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visted, int city) {
        visted[city] = true;
        int n = isConnected.size();
        for (int i=0;i<n;i++) {
            if (isConnected[city][i] == 1 && !visted[i]) {
                dfs(isConnected, visted, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visted(n, false);
        int provinces = 0;
        for (int i=0;i<n;i++) {
            if (!visted[i]) {
                provinces++;
                dfs(isConnected, visted, i);
            }
        }
        return provinces;
    }
};