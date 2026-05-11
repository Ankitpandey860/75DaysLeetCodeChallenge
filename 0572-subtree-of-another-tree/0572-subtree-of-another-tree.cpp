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
    bool isidt(TreeNode* root, TreeNode* sub){
        if(root==NULL&&sub==NULL) return true;
        if(root==NULL||sub==NULL) return false;
        if(root->val==sub->val){
            return isidt(root->left,sub->left)&&isidt(root->right,sub->right);
        }
        else
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            return isidt(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};