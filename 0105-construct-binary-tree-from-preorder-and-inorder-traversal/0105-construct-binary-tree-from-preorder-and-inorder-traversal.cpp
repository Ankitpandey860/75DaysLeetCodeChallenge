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
    TreeNode* solve(vector<int> &A, vector<int> &B,int &ip ,int ii,int ij){
        if(ip>=A.size()||ii>ij) return NULL;
        int curr=A[ip];
        TreeNode* root=new TreeNode(curr);
        int i=ii;
        while(i<=ij&&B[i]!=curr){
            i++;
        }
        ++ip;
        root->left=solve(A,B,ip,ii,i-1);
        root->right=solve(A,B,ip,i+1,ij);
        return root;
    }
    TreeNode* buildTree(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int i=0;
        return solve(A,B,i,0,n-1);
    }
};