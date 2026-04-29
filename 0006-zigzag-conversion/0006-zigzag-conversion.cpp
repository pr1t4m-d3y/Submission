class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1) return s;
        
        vector<string> rows(numRows);
        
        int curr=0;
        bool down=true;
        
        for(char ch : s){
            rows[curr] += ch;
            
            if(curr==0) down=true;
            if(curr==numRows-1) down=false;
            
            if(down) curr++;
            else curr--;
        }
        
        string ans="";
        for(string x:rows)
            ans+=x;
            
        return ans;
    }
};