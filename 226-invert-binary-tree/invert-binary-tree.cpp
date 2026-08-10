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
TreeNode* DFS(TreeNode* root){
    if(root==NULL)
    return NULL;
    TreeNode* L=DFS(root->left);
    TreeNode* R=DFS(root->right);

    root->left=R;
    root->right=L;
    return root;
}
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        DFS(root);
        return root;
    }
};