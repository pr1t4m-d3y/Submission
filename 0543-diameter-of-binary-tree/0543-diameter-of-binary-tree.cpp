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
        int heightOfTree(TreeNode* root, int& diam ){
            if (root==NULL) return 0;
            int left=heightOfTree(root->left,diam);
            int right=heightOfTree(root->right,diam);
            diam=max(diam, left+right);
            return 1+max(left,right);
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) return 0;
        int diam=0;
        int height = heightOfTree(root, diam);
        return diam;
        
    }
};