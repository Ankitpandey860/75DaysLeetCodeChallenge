class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dif=INT_MAX;
        int n=nums.size();
        int ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            int req=target-nums[i];
            while(j<k){
                int sum=nums[k]+nums[j];
                if(sum==req) return target;
                if(abs(req-sum)<dif){
                    dif=abs(req-sum);
                    ans=nums[i]+nums[j]+nums[k];
                }
                if(sum>req){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
