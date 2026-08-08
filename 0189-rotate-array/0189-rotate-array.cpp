class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector <int> arr(nums.size());
        // for (int i=0;i<nums.size();i++){
        //     arr[(i+k)% nums.size()]=nums[i];
        // }
        // nums=arr;
        int size=nums.size();
        k=k%size;
        for (int i=0;i<size/2; i++) swap(nums[i],nums[size-i-1]);
        for (int i=0;i<k/2;i++) swap(nums[i], nums[k-i-1]);

        int z=0;
        for (int i=k;i<(size+k)/2; i++){
            swap(nums[i],nums[size-1-z]);
            z++;
        }
    }
};