class Solution {
public:
    int solve(string &num,int idx,bool tight,bool ldzs,bool rep,int mask,vector<vector<vector<vector<vector<int>>>>>& dp){
        if(idx==num.length()) return rep;
        if(dp[idx][tight][ldzs][rep][mask]!=-1) return dp[idx][tight][ldzs][rep][mask];
        int ub=tight?num[idx]-'0':9;
        int res=0;
        for(int i = 0; i <= ub; i++) {

            bool newTight = tight && (i == ub);

            if(i == 0 && ldzs) {
                res += solve(num, idx+1, newTight, true, rep, mask, dp);
            }
            else {
                if(mask & (1<<i)) {
                    res += solve(num, idx+1, newTight, false, true, mask, dp);
                }
                else {
                    int newMask = mask | (1<<i);
                    res += solve(num, idx+1, newTight, false, rep, newMask, dp);
                }
            }
        }
        return dp[idx][tight][ldzs][rep][mask]=res;
    }
    int numDupDigitsAtMostN(int n) {
        string num=to_string(n);
        int len=num.length();
        vector<vector<vector<vector<vector<int>>>>> dp(
                                            len + 1,
                                            vector<vector<vector<vector<int>>>>(
                                                2,
                                                vector<vector<vector<int>>>(
                                                    2,
                                                    vector<vector<int>>(
                                                        2,
                                                        vector<int>(1025, -1)
                                                    )
                                                )
                                            )
                                        );
        return solve(num,0,true,true,false,0,dp);
    }
};