class Solution {
public:
    bool canwin(vector<int>& monsters,vector<long long>& bst,long long strength){
        for(int i=0;i<monsters.size();i++){
            if(bst[i]+strength<monsters[i]) return false;
            strength-=monsters[i];
            strength=max(0ll,strength);
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>bst(n,0);
        vector<long long> diff(n+1, 0);

        for(auto &it : boosts){
            int l = it[0];
            int r = it[1];
            long long b = it[2];

            diff[l] += b;
            if(r+1 < n)
                diff[r+1] -= b;
        }
        long long cur = 0;
        for(int i=0;i<n;i++){
            cur += diff[i];
            bst[i] = cur;
        }
        long long maxi=accumulate(monsters.begin(),monsters.end(),0ll);
        long long mini=0;
        long long ans=maxi;
        while(mini<=maxi){
            long long mid=mini+(maxi-mini)/2;
            if(canwin(monsters,bst,mid)){
                ans=mid;
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        return ans;
    }
};