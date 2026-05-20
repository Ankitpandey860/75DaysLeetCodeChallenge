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
    void trav(TreeNode* root,int curr,int& ans){
        if(root->left==NULL&&root->right==NULL){
            curr=curr*10+root->val;
            ans+=curr;
            return;
        }
        //left
        if(root->left)
        trav(root->left,curr*10+root->val,ans);
        //right
        if(root->right)
        trav(root->right,curr*10+root->val,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        trav(root,0,ans);
        return ans;
    }
};