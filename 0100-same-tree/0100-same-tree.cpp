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
        int dfs(TreeNode* p, TreeNode* q){
            if (p==NULL&& q==NULL) return 1;
            if ((p==NULL && q!=NULL)||(p!=NULL &&q==NULL))return 0;
            int left,right;
            if (p->val==q->val){
                left=dfs(p->left, q->left);
                right =dfs(p->right, q->right);
            }
            else return 0;
            if (left==0||right==0) return 0;
            return 1;
        }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int x=dfs(p, q);
        return x;
    }
};