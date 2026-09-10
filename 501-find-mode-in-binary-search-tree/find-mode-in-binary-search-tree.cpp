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
void dfs(TreeNode *root,vector<int>&ans){
    if(root==NULL)
    return;
    dfs(root->left,ans);
    ans.push_back(root->val);
    dfs(root->right,ans);
}
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans);
        int maxfreq=0;
        unordered_map<int,int>mp;
        for(auto x:ans){
            mp[x]++;
            maxfreq=max(maxfreq,mp[x]);
        }

    vector<int>fans;
    for(auto x:mp){
        if(x.second==maxfreq){
            fans.push_back(x.first);
        }
    }


    return fans;      
   
        
    }
};