class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result={""};
        for(int i=0;i<digits.size();i++){
            vector<string>temp;
            for(char c:pad[digits[i]-'0']){
                for(string s:result){
                    temp.push_back(s+c);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};