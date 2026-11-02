/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        int rl=1;
        if (root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode* temporary=q.front();
            q.pop();
            if (temporary==NULL){
                if (rl==1){
                    rl=0;
                    ans.push_back(temp);
                    temp.clear();
                }
                else{
                    rl=1;
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                    temp.clear();
                }
                if (!q.empty())q.push(NULL);
            }
            else{
                temp.push_back(temporary->val);
                if (temporary->left) q.push(temporary->left);
                if (temporary->right)q.push(temporary->right);
            }
        }
        return ans;
    }
};