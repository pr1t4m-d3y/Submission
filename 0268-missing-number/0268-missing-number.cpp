class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int sum=0,sum2=0;
        for (int i=1;i<=size;i++)
        sum+=i;

        for (int i=0;i<size;i++)
        sum2+=nums[i];

        return sum-sum2;
        
    }
};