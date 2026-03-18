class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod2=1;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                prod2*=nums[i];
            }
        }
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zero>1){
                    ans[i]=0;
                }
                else{
                    ans[i]=prod2;
                }
            }
            else{
                
                if(zero){
                    ans[i]=0;
                }
                else{
                    ans[i]=prod2/nums[i];
                }
            }
        }
        return ans;
    }
};