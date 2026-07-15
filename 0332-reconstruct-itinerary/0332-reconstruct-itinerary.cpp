class Solution {
public:
    void dfs(
        string src,vector<string>& ans,map<string, priority_queue<string, vector<string>, greater<string>>>& mp 
        )
    {
       
        while(mp[src].size()>0){
            string curr=mp[src].top();
            mp[src].pop();
            dfs(curr,ans,mp);
            
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,priority_queue<string, vector<string>, greater<string>>>mp;
        for(auto it:tickets){
            mp[it[0]].push(it[1]);
        }
        vector<string> ans;
        dfs("JFK",ans,mp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};