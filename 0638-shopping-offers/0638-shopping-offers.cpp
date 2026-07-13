class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index, unordered_map<string,int> &dp){
        string key = to_string(index) + "|";
        for(int x: needs)
            key += to_string(x) + "#";

        if(dp.count(key))
            return dp[key];
        if(index==special.size()){
            //Buy everything at the normal price
            int res = 0;
            for(int i=0;i<needs.size();i++){
                res += needs[i] * price[i];
            }
            return res;
        }

        // exc
        int exc=solve(price,special,needs,index+1,dp);

        //inc
        for(int i=0;i<needs.size();i++){
            needs[i] = needs[i] - special[index][i]; //Decrement the needs
            if(needs[i] < 0) return exc; //Can't use this offer
        }
        
        int accept = special[index][needs.size()] + solve(price, special, needs, index,dp);
        
        return dp[key] = min(accept, exc);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string,int> dp;
        return solve(price, special, needs, 0,dp);
    }
};