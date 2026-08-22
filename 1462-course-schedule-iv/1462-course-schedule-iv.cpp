class Solution {
public:
    bool ispre(int a,int b,vector<list<int>>& pre,vector<vector<int>>& dp){
        if(a==b) return true;
        if(dp[a][b]!=-1) return dp[a][b];
        bool is=false;
        for(auto it:pre[a]){
            is=is|ispre(it,b,pre,dp);
        }
        return dp[a][b]=is;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<list<int>>pre(numCourses);
        for(auto &it:prerequisites){
            int u=it[0];
            int v=it[1];
            pre[v].push_back(u);
        }
        vector<bool>ans;
        vector<vector<int>>dp(numCourses,vector<int>(numCourses,-1));
        for(auto it:queries){
            int a=it[0];
            int b=it[1];
            bool temp=ispre(b,a,pre,dp);
            ans.push_back(temp);
        }
        return ans;
    }
};