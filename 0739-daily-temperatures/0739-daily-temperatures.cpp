class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //monotonic stack:increasing or decreasing
        stack<int>st;
        //insert:st.push(val),delete:st.pop(),top:st.top()
        int n=temperatures.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
        while(!st.empty()&&temperatures[st.top()]<=temperatures[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top()-i;;
        }
        else{
            ans[i]=0;
        }
        st.push(i);
        }
        return ans;
    }
};