class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int bit=30;bit>=0;bit--){
            int temp=ans;
            bool poss=true;
            for(int i=0;i<n;i++){
                bool valid=false;
                for(int val:grid[i]){
                    int mask=(val&(INT_MAX<<bit));
                    if((temp|mask)==temp){
                        if(((val>>bit)&1)==0){
                            valid=true;
                            break;
                        }
                    }
                }
                if(!valid){
                    poss=false;
                }
            }
            if(!poss){
                ans=ans|(1<<bit);
            }
        }
        return ans;
    }
};