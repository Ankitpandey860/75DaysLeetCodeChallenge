class Solution {
public:
    void closest(vector<int>& nums,vector<int>& ans){
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans[i]=1;
            }
            else if(i==nums.size()-1){
                ans[i]=nums.size()-2;
                
            }
            else{
                if(abs(nums[i-1]-nums[i])<=abs(nums[i]-nums[i+1])){
                    ans[i]=i-1;
                }
                else{
                    ans[i]=i+1;
                }
            }
        }
    }
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>close(n);
        closest(nums,close);
        vector<long long>forward(n,0);
        for(int i=0;i<n-1;i++){
            if(close[i]==i+1){
                forward[i+1]=forward[i]+1;
            }
            else{
                forward[i+1]=forward[i]+nums[i+1]-nums[i];
            }
        }
        vector<long long>backward(n,0);
        for(int i=n-1;i>0;i--){
            if(close[i]==i-1){
                backward[i-1]=backward[i]+1;
            }
            else{
                backward[i-1]=backward[i]+nums[i]-nums[i-1];
            }
        }
        vector<int>ans;
        for(auto &q:queries){
            int u=q[0],v=q[1];
            if(u<v){
                ans.push_back(forward[v]-forward[u]);
            }
            else{
                ans.push_back(backward[v]-backward[u]);
            }
        }
        return ans;
    }
};