/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, unordered_set<int> mp, int is_root) {
        if (root == nullptr)
            return;
        if (mp.find(root->val) != mp.end()) {
            dfs(root->left, mp, true);
            dfs(root->right, mp, true);
        } else {
            if (is_root) {
                ans.push_back(root);
            }
            TreeNode* leftnode = root->left;
            TreeNode* rightnode = root->right;
            if (root->left) {
                if (mp.find(root->left->val) != mp.end())
                    root->left = nullptr;
            }
            if (root->right) {
                if (mp.find(root->right->val) != mp.end())
                    root->right = nullptr;
            }
            dfs(leftnode, mp, false);
            dfs(rightnode, mp, false);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> mp(to_delete.begin(), to_delete.end());
        dfs(root, mp, true);
        return ans;
    }
};
