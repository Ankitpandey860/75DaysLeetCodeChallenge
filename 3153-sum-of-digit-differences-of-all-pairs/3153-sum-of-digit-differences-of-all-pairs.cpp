class Solution {
public:
    int len(int n){
        int ans=0;
        while(n>0){
            ans++;
            n/=10;
        }
        return ans;
    }
    long long sumDigitDifferences(vector<int>& nums) {
        int lim=min(10,len(nums[0]));
        vector<vector<int>>temp(lim,vector<int>(10,0));
        
        for(int i=0;i<lim;i++){
            for(int j=0;j<nums.size();j++){
                int dig=nums[j]%10;
                nums[j]/=10;
                temp[i][dig]++;
            }
        }
        long long ans=0;
        for(int i=0;i<lim;i++){
            for(int j=0;j<10;j++){
                if(temp[i][j]==0)continue;
                for(int k=j+1;k<10;k++){
                    if(temp[i][k]==0) continue;
                    //int diff=abs(j-k);
                    long long curr=1ll*temp[i][j]*1ll*temp[i][k];
                    ans+=curr;
                }
            }
        }
        return ans;
    }
};