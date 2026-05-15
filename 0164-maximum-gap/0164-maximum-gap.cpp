class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int n=nums.size();
        auto res=minmax_element(nums.begin(),nums.end());
        int mini=*res.first;
        int maxi=*res.second;
        int size=max(1,(maxi-mini)/(n-1));
        int nofbuck=(maxi-mini)/size + 1;
        vector<vector<int>>bucket(nofbuck,vector<int>(2));
        for(int i=0;i<nofbuck;i++){
            bucket[i][0]=INT_MAX;
            bucket[i][1]=INT_MIN;
        }
        for(int i=0;i<nums.size();i++){
            int idx=(nums[i]-mini)/size;
            bucket[idx][0]=min(nums[i],bucket[idx][0]);
            bucket[idx][1]=max(nums[i],bucket[idx][1]);
        }
        int ans=0;
        for(int i=1;i<nofbuck;i++){
            if(bucket[i][1]==INT_MIN) continue;
            int j=i-1;
            while(bucket[j][0]==INT_MAX&&j>0){
                j--;
            }
            ans=max(ans,bucket[i][0]-bucket[j][1]);
        }
        return ans;
    }
};

