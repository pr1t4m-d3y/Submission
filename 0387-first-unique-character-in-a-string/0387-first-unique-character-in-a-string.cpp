class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,0);
        for (int i=0;i<s.size();i++){
            int num=s[i]-'a';
            arr[num]++;
        }
        for (int i=0;i<s.length();i++){
            int num= arr[s[i]-'a'];
            if (num==1) return i;
        }
        int num=-1;
        return num;
    }
};