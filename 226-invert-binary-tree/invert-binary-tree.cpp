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


//..................  APP-1...........................

// class Solution {
// public:
// TreeNode* DFS(TreeNode* root){
//     if(root==NULL)
//     return NULL;
//     TreeNode* L=DFS(root->left);
//     TreeNode* R=DFS(root->right);

//     root->left=R;
//     root->right=L;
//     return root;
// }
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==NULL)
//         return NULL;
//         DFS(root);
//         return root;
//     }
// };







// .............................APP-2.....................
class Solution {
public:
void BFS(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        TreeNode* temp=curr->left;
        curr->left=curr->right;
        curr->right=temp;
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
    }
}
    TreeNode* invertTree(TreeNode* root) { 
        if(root==NULL)
        return NULL;
        BFS(root);
        return root;
        
    }
};