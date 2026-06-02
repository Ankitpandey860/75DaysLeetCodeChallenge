class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            maxp=max(maxp,prices[i]-buy);
        }
        return maxp;
    }
};