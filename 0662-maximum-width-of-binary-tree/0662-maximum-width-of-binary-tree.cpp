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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long len=1;
        while(!q.empty()){
            int cnt=q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            len=max(len,end-start+1);
            
            for(int i=0;i<cnt;i++){
                TreeNode* temp=q.front().first;
                long long curr=q.front().second;
                q.pop();
                long long idx=curr-start;
                if(temp->left){
                    q.push({temp->left,1ll*2*idx});
                }
                if(temp->right){
                    q.push({temp->right,1ll*2*idx+1});
                }
            }
        }
        return (int)len;
    }
};