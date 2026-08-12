class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <int> arr;
        for (auto ch: s) arr.push(ch);

        int open=0, close=0;
        while (!arr.empty()){
            int top=arr.top();
            arr.pop();
            if (!arr.empty() && top==')' && arr.top()=='(' ) arr.pop();
            else{
                if (top=='('){
                    if (close!=0) close--;
                    else open++;
                }
                else close++;
            }
        }
        return open+close;
    }
};