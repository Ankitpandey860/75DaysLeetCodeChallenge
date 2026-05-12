class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,bool>mp;
        for(int i=0;i<bulbs.size();i++){
            if(mp.find(bulbs[i])!=mp.end()){
                mp[bulbs[i]]=!mp[bulbs[i]];
            }
            else{
                mp[bulbs[i]]=true;
            }
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};