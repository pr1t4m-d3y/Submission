class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,i=1;
        if (nums.size()==0)return 0;
        if (nums.size()==1)return nums.size();
        while (i<nums.size()){
            if (nums[i]==nums[j]){
                i++;
            }
            else {
                swap(nums[i],nums[j+1]);
                j++;
                i++;
            }
        }
        
        return j+1;
    }
};