class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int>st(n,1);
        vector<int>end(n,1);
        for(int i=1;i<n;i++){
            if(i>=2&&nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                st[i]=1+st[i-1];
            }
            else{
                st[i]=2;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(i<=n-3&&nums[i]-nums[i+1]==nums[i+1]-nums[i+2]){
                end[i]=1+end[i+1];
            }
            else{
                end[i]=2;
            }
        }
        int ans=2;
        for(int i=0;i<n;i++){
            ans=max(ans,st[i]+1);
        }
        for(int i=1;i<n-1;i++){
            int t=nums[i+1]-nums[i-1];
            if(t%2==0){
                int left=1;
                int d=t/2;
                if(i>=2&&nums[i-1]-nums[i-2]==d){
                    left=st[i-1];
                }
                int right=1;
                if(i<n-2&&nums[i+2]-nums[i+1]==d){
                    right=end[i+1];
                }
                ans=max(ans,left+right+1);
            }
        }
        return min(ans,n);
    }
};