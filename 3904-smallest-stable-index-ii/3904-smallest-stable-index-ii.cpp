class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN,mini=INT_MAX;
        vector<int> left(n),right(n);
        for(int i=n-1;i>=0;i--){
            mini=min(nums[i],mini);
            right[i]=mini;
        }
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            left[i]=maxi;
        }
        for(int i=0;i<n;i++){
            if((left[i]-right[i])<=k) return i;
        }
        return -1;
    }
};