class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i*i*i<=n;i++){
            mp[i*i*i]++;
        }
        unordered_map<int,int>mp2;
        for(auto it1:mp){
            for(auto it2:mp){
                if(it1.first<=it2.first){
                    int req=it1.first+it2.first;
                    if(req<=n)
                        mp2[req]++;
                }
            }
        }
        vector<int>ans;
        for(auto it:mp2){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};