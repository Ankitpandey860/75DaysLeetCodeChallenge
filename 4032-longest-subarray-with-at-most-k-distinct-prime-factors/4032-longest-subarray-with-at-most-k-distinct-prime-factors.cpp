class Solution {
public:
    vector<int>pfactor(int n){
        vector<int>ans;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0)
                    n/=i;
            }
        }

        if(n>1) ans.push_back(n);

        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>prefix(n);
        for(int i=0;i<n;i++){
            prefix[i]=pfactor(nums[i]);
        }
        int i=0,j=0;
        int ans=0;
        int unique=0;
        int odd=0;
        unordered_map<int,int>mp;
        while(j<n){
            for(auto &it:prefix[j]){
                mp[it]++;
                if(mp[it]==1) unique++;
                //if(mp[it]%2==1) odd++;
                //else odd--;
            }
            while(i<=j&&unique>k){
                for(auto &it:prefix[i]){
                    mp[it]--;
                    if(mp[it]==0) unique--;
                  //  if(mp[it]%2==1) odd++;
                  //  else odd--;
                }
                i++;
            }
            //if(odd=0){
                ans=max(ans,j-i+1);
            //}
            j++;
        }
        return ans;
    }
};