class Solution {
public:
    void subset(vector<int>& nums,int i,unordered_set<int>& st,vector<vector<int>>& ans,vector<int>& temp){
        if(i>=nums.size()) {
            ans.push_back(temp);
            return;
        }
        //  if not take then exc
        if(st.find(nums[i])==st.end()){
            //exc
            subset(nums,i+1,st,ans,temp);
        }
        //inc
        temp.push_back(nums[i]);
        st.insert(nums[i]);
        subset(nums,i+1,st,ans,temp);
        temp.pop_back();
        st.erase(nums[i]);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_set<int>st;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        subset(nums,0,st,ans,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};