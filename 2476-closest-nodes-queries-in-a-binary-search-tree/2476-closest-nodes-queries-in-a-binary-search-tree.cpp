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
    void dfs(TreeNode* root,vector<int>& ordr){
        if(root==NULL) return;
        dfs(root->left,ordr);
        ordr.push_back(root->val);
        dfs(root->right,ordr);
    }
    int minsearch(vector<int>& nums,int val){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<=val){
                ans=nums[mid];
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    int maxsearch(vector<int>& nums,int val){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>=val){
                ans=nums[mid];
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>sorted;
        dfs(root,sorted);

        vector<vector<int>>ans;
        for(auto it:queries){
            int mini=minsearch(sorted,it);
            int maxi=maxsearch(sorted,it);
            ans.push_back({mini,maxi});
        }
        return ans;
    }
};