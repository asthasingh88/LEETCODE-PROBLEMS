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
    void DFS(TreeNode* root, int CS, int &root_to_leaf) {
        if (root == NULL) return;   // base case

        CS = CS * 10 + root->val;   // build current number

        // if it's a leaf, add to sum
        if (root->left == NULL && root->right == NULL) {
            root_to_leaf += CS;
            return;
        }

        // recurse on children
        DFS(root->left, CS, root_to_leaf);
        DFS(root->right, CS, root_to_leaf);
    }

    int sumNumbers(TreeNode* root) {
        int root_to_leaf = 0;
        DFS(root, 0, root_to_leaf);
        return root_to_leaf;
    }
};
