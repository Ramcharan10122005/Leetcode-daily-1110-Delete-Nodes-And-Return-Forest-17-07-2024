int ansSize;
struct TreeNode** ans;

bool hash[1001];

void dfs(struct TreeNode* root, int is_root) {
    if (root == NULL)
        return;
    if (hash[root->val]) {
        dfs(root->left, 1);
        dfs(root->right, 1);
        free(root);
    } else {
        if (is_root) {
            ans[ansSize++] = root;
        }
        struct TreeNode* leftnode = root->left;
        struct TreeNode* rightnode = root->right;
        if (root->left && hash[root->left->val]) {
            root->left = NULL;
        }
        if (root->right && hash[root->right->val]) {
            root->right = NULL;
        }
        dfs(leftnode, 0);
        dfs(rightnode, 0);
    }
}

struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize) {
    ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    ansSize = 0;

    for (int i = 0; i < 1001; i++) {
        hash[i] = false;
    }
    for (int i = 0; i < to_deleteSize; i++) {
        hash[to_delete[i]] = true;
    }

    dfs(root, 1);

    *returnSize = ansSize;
    return ans;
}
