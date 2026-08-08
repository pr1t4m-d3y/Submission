class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector <int> arr(nums.size());
        // for (int i=0;i<nums.size();i++){
        //     arr[(i+k)% nums.size()]=nums[i];
        // }
        // nums=arr;
        

        k=k% (nums.size());

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};