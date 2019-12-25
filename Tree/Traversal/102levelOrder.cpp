/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        int width = 0;

        if (NULL != root) q.push(root);

        while (!q.empty()) {
            width = q.size();
            vector<int> x;
            while (width--) {
                root = q.front();
                q.pop();
                x.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            v.push_back(x);
        }
        return v;
    }
};