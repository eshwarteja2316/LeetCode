class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visted, int room) {
        visted[room] = true;
        for(int key : rooms[room]) {
            if (!visted[key]) {
                dfs(rooms, visted, key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visted(n, false);
        dfs(rooms, visted, 0);
        for (int i=0;i<n;i++) {
            if(!visted[i]) {
                return false;
            }
        }
        return true;
    }
};