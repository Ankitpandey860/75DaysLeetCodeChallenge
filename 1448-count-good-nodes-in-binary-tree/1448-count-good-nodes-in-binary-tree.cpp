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
    int traverse(TreeNode* root,int curr){
        if(root==NULL) return 0;
        if(root->val>=curr){
            return 1+traverse(root->left,root->val)+traverse(root->right,root->val);
        }
        else{
            return traverse(root->left,curr)+traverse(root->right,curr);
        }
    }
    int goodNodes(TreeNode* root) {
        return traverse(root,-10005);
    }
};