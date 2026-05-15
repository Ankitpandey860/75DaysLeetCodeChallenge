class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<unordered_map<long,long>>mp(n);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long d=1ll*nums[i]-1ll*nums[j];
                //ending at i
                int endi=0;
                int endj=0;
                if(mp[i].find(d)!=mp[i].end()){
                    endi=mp[i][d];
                }
                if(mp[j].find(d)!=mp[j].end()){
                    endj=mp[j][d];
                }
                ans+=endj;
                mp[i][d]=endi+endj+1;
            }
        }
        return ans;
    }
};