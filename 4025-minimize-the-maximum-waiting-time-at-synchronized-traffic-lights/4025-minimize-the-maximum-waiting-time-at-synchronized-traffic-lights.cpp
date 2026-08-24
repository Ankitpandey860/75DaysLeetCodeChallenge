class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi=0;
        for(auto it:lights){
            maxi=max(it,maxi);
        }
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++){
            arrivalTime[i]=arrivalTime[i]%period;
            if(arrivalTime[i]>=maxi)
                ans=max(ans,period-arrivalTime[i]);
        }
        return ans;
    }
};