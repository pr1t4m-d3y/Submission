class Solution {
private:
void recurssion (vector <int> arr, vector<vector<int>>&ans, vector<int> &current, int i){
    if(i>=arr.size()){
        ans.push_back(current);
        return;
    }
    
    current.push_back(arr[i]);
    recurssion(arr, ans, current, i+1);

    current.pop_back();
    recurssion (arr, ans,current, i+1);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector < vector <int>> ans;
        vector <int> current;
        recurssion(nums,ans,current, 0);
        return ans;
    }
};