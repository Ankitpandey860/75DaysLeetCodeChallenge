class Solution {
public:
     bool operation(int k, vector<int>& nums) {
        int n=nums.size();
        int chunks=n/k;
        vector<pair<int,int>>minmax(chunks);
        for(int i=0;i<chunks;i++){
            int start=i*k;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            int cnt=0;
            for(int j=0;j<k;j++){
                int curr=nums[start+j];
                int next=nums[start+(j+1)%k];
                if(curr>next){
                    cnt++;
                }
                mini=min(curr,mini);
                maxi=max(curr,maxi);
            }
            minmax[i].first=mini;
            minmax[i].second=maxi;
            if(cnt>1) return false;
        }
        for(int i=0;i<chunks-1;i++){
            int currmax=minmax[i].second;
            int nextmin=minmax[i+1].first;
            if(nextmin<currmax) return false;
        }
        return true;
     }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (operation(i, nums)) ans += i;

                if (i != n / i) {
                    if (operation(n / i, nums)) ans += (n / i);
                }
            }
        }

        return ans;
    }
};