class Solution {
    void recurssion (vector<int>& nums, vector<vector<int>>& ans, int index=0){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i=index;i<nums.size();i++){
            swap(nums[i], nums[index]);
            recurssion(nums, ans, index+1);

            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurssion(nums, ans);
        return ans;
    }
};