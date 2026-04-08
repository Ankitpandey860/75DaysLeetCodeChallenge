class Solution {
public:
    void solve(int st, int end,int k,vector<vector<int>>& ans,vector<int> temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(k==1){
             temp.push_back(st);
             ans.push_back(temp);
             return;
        }
        if(st>end) return;
        temp.push_back(st);
        for(int i=st+1;i<=end;i++){
            solve(i,end,k-1,ans,temp);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1;i<=n;i++){
            solve(i,n,k,ans,temp);
        }
        return ans;
    }
};