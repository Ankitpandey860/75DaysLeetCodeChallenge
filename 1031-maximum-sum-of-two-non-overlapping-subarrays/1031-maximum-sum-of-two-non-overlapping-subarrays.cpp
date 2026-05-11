class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        int n=nums.size();
        vector<int>leftx(n),rightx(n),lefty(n),righty(n);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i<x){
                
                sum+=nums[i];
                leftx[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i-x];
                leftx[i]=max(sum,leftx[i-1]);
            }
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(i<y){
                
                sum+=nums[i];
                lefty[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i-y];
                lefty[i]=max(sum,lefty[i-1]);
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(i+y>=n){
                
                sum+=nums[i];
                righty[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+y];
                righty[i]=max(rightx[i+1],sum);
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(i+x>=n){
               
                sum+=nums[i];
                 rightx[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+x];
                rightx[i]=max(rightx[i+1],sum);
            }
        }
        int ans=0;
        //left x right y
        for(int i=x-1;i<n-y;i++){
            ans=max(ans,leftx[i]+righty[i+1]);
        }
        for(int i=y-1;i<n-x;i++){
            ans=max(ans,lefty[i]+rightx[i+1]);
        }
        return ans;
    }
};