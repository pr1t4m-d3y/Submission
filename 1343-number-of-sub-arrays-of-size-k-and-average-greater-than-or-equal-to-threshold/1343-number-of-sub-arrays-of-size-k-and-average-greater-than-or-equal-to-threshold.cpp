class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start=0,sum=0,total,ans=0;
        for (int i=0;i<k;i++){
            sum+=arr[i];
        }
        total=sum/k;
        if (total>=threshold) ans++;
        for (int i=k;i<arr.size();i++){
            sum+=arr[i];
            sum-=arr[start++];
            total=sum/k;
            if (total>=threshold) ans++;
        }
        return ans;
    }
};

