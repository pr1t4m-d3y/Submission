class Solution {
public:
    bool isValid(string s) {
        stack<char> arr;
        for (auto ch: s){
            if (ch=='(' || ch=='{' || ch=='[') arr.push(ch);

            else if (!arr.empty()){
                char top=arr.top();
                if (ch==')' && top=='(' || ch=='}' && top=='{' || ch==']'&& top=='[') arr.pop();
                else return 0;
            }
            else return 0;
        }
        return (arr.empty());
    }
};