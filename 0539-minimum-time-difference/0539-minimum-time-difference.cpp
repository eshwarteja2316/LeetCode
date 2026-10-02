class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string time:timePoints) {
            int hours = stoi(time.substr(0,2));
            int mins = stoi(time.substr(3,2));

            minutes.push_back(hours*60+mins);
        }
        sort (minutes.begin(), minutes.end());

        int ans = 1440;

        for (int i=1;i<minutes.size();i++) {
            ans = min(ans, minutes[i]- minutes[i-1]);
        }
        int circular = 1440-minutes.back() + minutes[0];
        ans = min(ans, circular);

        return ans;
    }
};