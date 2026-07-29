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
 int height(TreeNode* root){
    if(root ==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
 }
 void printLevel(TreeNode* root,int level,vector<int>&curr){
    if(root==NULL)
    return;
    if(level==1)
    curr.push_back(root->val);
    else{
        printLevel(root->left,level-1,curr);
        printLevel(root->right,level-1,curr);

    }
 }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=height(root);
        vector<vector<int>>ans;
        for(int i=1;i<=h;i++){
            vector<int>curr;
            printLevel(root,i,curr);
            ans.push_back(curr);
        }
      return ans;  
    }
};