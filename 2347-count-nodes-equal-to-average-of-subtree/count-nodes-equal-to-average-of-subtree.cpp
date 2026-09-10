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

    // Given node ke subtree ka SUM
    int getSum(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            sum += curr->val;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        return sum;
    }

    // Given node ke subtree ka COUNT
    int getCount(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int count = 0;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            count++;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        return count;
    }

    int solve(TreeNode* root) {

        if(root == NULL)
            return 0;

        int sum = getSum(root);
        int count = getCount(root);

        int ans = 0;

        if(sum / count == root->val)
            ans = 1;

        ans += solve(root->left);
        ans += solve(root->right);

        return ans;
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};