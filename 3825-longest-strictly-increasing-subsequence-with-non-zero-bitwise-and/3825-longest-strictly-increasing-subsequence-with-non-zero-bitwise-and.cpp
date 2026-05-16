class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int ans=0;
        for(int i=0;i<31;i++){
            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){
                    if(temp.empty()||nums[j]>temp.back()){
                        temp.push_back(nums[j]);
                    }
                    else{
                        int index=lower_bound(temp.begin(),temp.end(),nums[j])-temp.begin();
                        temp[index]=nums[j];
                    }
                }
            }
            ans=max(ans,(int)temp.size());
        }
        return ans;
    }
};