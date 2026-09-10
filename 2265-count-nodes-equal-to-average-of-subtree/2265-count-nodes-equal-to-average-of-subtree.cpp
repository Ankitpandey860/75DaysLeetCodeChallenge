class Solution {
public:
    pair<int,int>dfs2(TreeNode* root,int &ans){
        if(root==NULL) return make_pair(0,0);
        auto l=dfs2(root->left,ans);
        auto r=dfs2(root->right,ans);
        int sum=l.first+r.first+root->val;
        int cnt=l.second+r.second+1;
        if(sum/cnt==root->val) ans++;
        return make_pair(sum,cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs2(root,ans);
        return ans;
    }
};