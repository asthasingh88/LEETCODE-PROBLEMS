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
    TreeNode* Xparent = NULL;
    TreeNode* Yparent = NULL;

    int Xdepth = -1;
    int Ydepth = -1;

    void DFS(TreeNode* root, int X, int Y, TreeNode* parent, int depth) {
        
        if(root == NULL)
            return;

        // X mila
        if(root->val == X) {
            Xparent = parent;
            Xdepth = depth;
        }

        // Y mila
        if(root->val == Y) {
            Yparent = parent;
            Ydepth = depth;
        }

        // Current root is parent of its children
        DFS(root->left, X, Y, root, depth + 1);
        DFS(root->right, X, Y, root, depth + 1);
    }

    bool isCousins(TreeNode* root, int x, int y) {

        if(root == NULL)
            return false;

        DFS(root, x, y, NULL, 0);

        if(Xparent != Yparent && Xdepth == Ydepth)
            return true;

        return false;
    }
};