class Solution {
public:
    void solve(vector<int>& candidates,int target,int i,vector<int>& temp,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0||i>=candidates.size()){
            return ;
        }
        for(int idx=i;idx<candidates.size();idx++){
            if(idx>i&&candidates[idx]==candidates[idx-1]) continue;
            if(candidates[idx]>target) break;
            temp.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],idx+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        /*vector<int>cdk;
        cdk.push_back(candidates[0]);
        for(int i=1;i<candidates.size();i++){
            if(candidates[i]!=cdk.back()){
                cdk.push_back(candidates[i]);
            }
        }*/
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,0,temp,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};