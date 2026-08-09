class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        string ans="";
        int mid=-1;
        for(int i=0;i<=25;i++){
            char c=char(97+i);
            if(mp.count(c)){
                int n=mp[c];
                if(n%2){
                    mid=i;
                }
                int l=mp[c]/2;
                mp[c]-=l;
                ans+=string(l,c);
            }
        }
        if(mid==-1&&s.size()==2){
            return s;
        }
        else{
            if(mid!=-1){
            char c=char(97+mid);
            ans+=c;
            mp[c]--;
            }
            for(int i=25;i>=0;i--){
                char c1=char(97+i);
                 if(mp.count(c1)){
                int n=mp[c1];
                if(n%2){
                    mid=i;
                }
                int l=mp[c1];
                mp[c1]-=l;
                ans+=string(l,c1);
            }
            }
        }
        return ans;
    }
};