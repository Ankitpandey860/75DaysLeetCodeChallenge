class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1),right(n,1);
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                right[i]=right[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            int prev=i>0?left[i-1]:0;
            int next=i<n-1?right[i+1]:0;
            if(i>0&&i<n-1&&nums[i-1]<=nums[i+1]){
                ans=max(ans,prev+next+1);
            }
            ans=max(ans,prev+1);
            ans=max(ans,next+1);
        }
        return min(ans,n);
    }
};