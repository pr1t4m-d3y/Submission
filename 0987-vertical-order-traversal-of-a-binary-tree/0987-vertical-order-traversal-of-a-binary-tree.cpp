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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int>> ans;

        if (root == NULL) return ans;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            mp[hd][level].push_back(node->val);

            if (node->left)
                q.push({node->left, {hd - 1, level + 1}});

            if (node->right)
                q.push({node->right, {hd + 1, level + 1}});
        }

        for (auto &i : mp) {
            vector<int> col;

            for (auto &j : i.second) {
                sort(j.second.begin(), j.second.end());

                for (auto k : j.second) {
                    col.push_back(k);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};
