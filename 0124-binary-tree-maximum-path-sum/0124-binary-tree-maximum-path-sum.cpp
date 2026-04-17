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
    int maxi=INT_MIN;
    int solve(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL){
            maxi=max(maxi,root->val);
            return root->val;
        }
        int left = INT_MIN, right = INT_MIN;
        if(root->left){
            left=solve(root->left);
        }
        if(root->right){
            right=solve(root->right);
        }
         
        int withleft = (left == INT_MIN ? 0 : left) + root->val;
        int withright = (right == INT_MIN ? 0 : right) + root->val;
        int total = (left == INT_MIN ? 0 : left) + (right == INT_MIN ? 0 : right) + root->val;
        maxi=max({left,right,withleft,withright,total,root->val,maxi});
        int ans=max(root->val,max(withleft,withright));
        return ans;

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};