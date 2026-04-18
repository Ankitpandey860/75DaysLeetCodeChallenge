class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int bit=30;bit>=0;bit--){
            int temp=ans;

            bool poss=true;//possibleee h iskooo htana
            for(int i=0;i<n;i++){
                bool valid=false;
                for(int val:grid[i]){
                    int mask=(val & (INT_MAX << bit));

                    if((temp|mask)==temp){

                        if((val>>bit&1)==0){
                            valid=true;
                            break;
                        }
                    }
                }
                if(!valid){
                    poss=false;
                    break;
                }
            }
            if(!poss){
                ans=ans|(1<<bit);
            }
        }
        return ans;
    }
};