class Solution {
public:
    int maxVowels(string s, int k) {
        int start=0,maxi=INT_MIN, sum=0;
        for (int i=0;i<k;i++){
            char ch=s[i];
            if (ch=='a' || ch=='e'|| ch=='i'||ch=='o'||ch=='u') sum++;
        }
        maxi=sum;
        for (int i=k;i<s.length();i++){
            char ch=s[i];
            if (ch=='a' || ch=='e'|| ch=='i'||ch=='o'||ch=='u') sum++;
            char ch1=s[start++];
            if (ch1=='a' || ch1=='e'|| ch1=='i'||ch1=='o'||ch1=='u') sum--;

            maxi=max(sum,maxi);
        }
        return maxi;
        
    }
};