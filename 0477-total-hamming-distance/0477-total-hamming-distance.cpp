class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        int maxi=INT_MIN;
        for(auto it:nums){
            maxi=max(it,maxi);
        }
        long long i=1;
        while(i<=maxi){
            int zero=0;
            int one=0;
            for(auto it:nums){
                if(it&i){
                    one++;
                }
                else{
                    zero++;
                }
            }
            int curr=one*zero;
            ans+=curr;
            i=i<<1;
        }
        return ans;
    }
};