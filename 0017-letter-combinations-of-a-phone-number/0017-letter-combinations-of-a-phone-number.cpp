class Solution {
    void backtrack(string digits, vector<string> &ans,string &current, string map[], int index ){
        if(index>=digits.length()){
            ans.push_back(current);
            return;
        }
        int d=digits[index]-'0';
        string s= map[d];

        for (int i=0;i<s.length();i++){
         current.push_back(s[i]);
         backtrack(digits, ans, current, map, index+1);  
         current.pop_back(); 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        if (digits.length()<1)
        return ans;
        string current="";
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(digits, ans, current, map, 0);
        return ans;
    }
};