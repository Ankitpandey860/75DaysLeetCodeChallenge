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
    int solve(TreeNode* root,int& ans){
        if(root->left==NULL&&root->right==NULL) return 1;
        int left=0,right=0;
        if(root->left)
        left=solve(root->left,ans);
        if(root->right)
        right=solve(root->right,ans);
        ans=max(ans,max(left,max(right,left+right)));
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};