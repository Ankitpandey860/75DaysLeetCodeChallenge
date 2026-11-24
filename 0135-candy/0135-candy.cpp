class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>prefix(n,1),suffix(n,1),ans(n);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=max(prefix[i],suffix[i]);
        }
        int res=0;
        for(int x:ans){
            res+=x;
        }
        return res;
    }
};