/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>res;
       

        // }
        // TreeNode *curr=root;
        // stack<TreeNode*>st;
        // while(curr!=NULL || !st.empty()){
        //     while(curr!=NULL){
        //         st.push(curr);
        //         curr=curr->left;
        //     }
        //     curr=st.top();
        //     st.pop();
        //     res.push_back(curr->val);
        //     curr=curr->right;
        // }
        // return res;
    
//     }
// };




class Solution {
public:
    vector<int> res;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};