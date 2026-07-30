class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefix(n);
        int curr=0;
        for(int i=0;i<n;i++){
            curr^=arr[i];
            prefix[i]=curr;
        }
        int m=queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            int curr=prefix[r];
            int prev=l==0?0:prefix[l-1];
            ans[i]=curr^prev;
        }
        return ans;
    }
};