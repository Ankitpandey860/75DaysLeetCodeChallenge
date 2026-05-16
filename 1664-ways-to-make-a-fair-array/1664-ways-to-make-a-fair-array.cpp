class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 1;

        vector<int> v(n + 2);
        v[2] = nums[0];
        v[3] = nums[1];
        int ans = 0;

        for (int i = 2; i < n; i++) {
            v[i + 2] = v[i] + nums[i];
        }
        for(int i=2;i<=n+1;i++){
            int nxtodd=0,nxteven=0;
            int odd=0,even=0;
            if(i%2){
                even=v[i-1];
                odd=v[i-2];
                if((n+1)%2){
                    nxtodd=v[n+1]-v[i];
                    nxteven=v[n]-even;
                }
                else{
                    nxtodd=v[n] -v[i];
                    nxteven=v[n+1]-even;
                }
            }
            else{
                even=v[i-2];
                odd=v[i-1];
                if ((n + 1) % 2) {
                    nxtodd = v[n + 1] - odd;
                    nxteven = v[n] - v[i];
                } else {
                    nxtodd = v[n] - odd;
                    nxteven = v[n + 1] - v[i];
                }
            }
            if(nxtodd+even==nxteven+odd) ans++;
        }
        return ans;
    }
};