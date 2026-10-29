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
        int height(TreeNode* root, bool& bal){
            if (root==NULL) return 0;
            int left = height(root->left, bal);
            int right=height (root->right, bal);
            if (abs(left-right)>1)bal=false;
            return 1+ max(left, right);
        }
public:
    bool isBalanced(TreeNode* root) {
        bool bal=true;
        int x=height(root, bal);
        return bal;
        
    }
};