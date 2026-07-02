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
    pair<int,TreeNode*> trav(TreeNode* root,int x,int level){
         if(root==NULL) return {-1,NULL};

        if((root->left && root->left->val==x) ||
           (root->right && root->right->val==x))
            return {level,root};

        auto left = root->left
                    ? trav(root->left,x,level+1)
                    : pair<int,TreeNode*>{-1,NULL};

        auto right = root->right
                     ? trav(root->right,x,level+1)
                     : pair<int,TreeNode*>{-1,NULL};

        if(left.second) return left;
        return right;

    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto xpar=trav(root,x,0);
        auto ypar=trav(root,y,0);
        return (xpar.second!=ypar.second)&&(xpar.first==ypar.first);
    }
};