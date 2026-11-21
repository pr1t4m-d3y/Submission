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
private:
    void targetSearch(TreeNode* root, int targetSum, int &count,bool &isValid){
        if (root==NULL) return;
        count+=root->val;
        if (root->left==NULL && root->right==NULL){
            if (count==targetSum){
                isValid=true;
                return;
            }
        }
        
        if (root->left) {targetSearch(root->left, targetSum, count,isValid);
        count-=root->left->val;}
        if (isValid) return;
        
        if (root->right) {targetSearch(root->right, targetSum, count,isValid);count-=root->right->val;}
        if(isValid) return;
        

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL) return false;
        bool isValid=false;

        if (root->val==targetSum && (root->left==NULL && root->right==NULL)) return true;

        int count=root->val;

        targetSearch(root->left, targetSum,count,isValid);
        if (isValid) return isValid;
        count=root->val;
        targetSearch(root->right,targetSum,count,isValid);
        if (isValid) return isValid;

        return isValid;
    }
};