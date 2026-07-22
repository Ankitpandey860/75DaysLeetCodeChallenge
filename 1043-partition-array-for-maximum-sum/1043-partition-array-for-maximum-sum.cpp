class Solution {
public:
    int solve(vector<int>& arr, int &k,int i,int maxi,int len,vector<vector<int>>& dp){
        if(i>=arr.size()){
            if(maxi>=arr.size()) return 0;
            return  len*arr[maxi];
        }
        if(dp[i][len]!=-1) return dp[i][len];
        int inc=0,exc=0;
        if(k>len){        // ya toh partition krdu yaa aagee badh jauu isee jod ke
            
            // isee nhi jodungaa 

            exc=len*arr[maxi]+solve(arr,k,i+1,i,1,dp);
            // isee add kroo ismee
            if(arr[i]>arr[maxi]){
                maxi=i;
            }
            inc=solve(arr,k,i+1,maxi,len+1,dp);


        }
        else{           // limit exit partition krna pdega
            exc=len*arr[maxi]+solve(arr,k,i+1,i,1,dp);
        }
        return dp[i][len]=max(exc,inc);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
       // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
       vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(arr,k,1,0,1,dp);
    }
};