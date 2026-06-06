class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(auto it:deck){
            mp[it]++;
        }
        int g=mp[0];
        for(auto it:mp){
            g=gcd(g,it.second);
        }
        return g>=2;
    }
};