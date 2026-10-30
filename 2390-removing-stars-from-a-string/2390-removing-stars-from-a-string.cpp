class Solution {
public:
    string removeStars(string s) {
        int size=s.size();

        for (int i=0;i<size;i++){
            char ch=s[i];
            if (ch=='*'){
                s.erase(i-1,2);
                size-=2;
                i-=2;}
                
        }
        return s;
    }
};