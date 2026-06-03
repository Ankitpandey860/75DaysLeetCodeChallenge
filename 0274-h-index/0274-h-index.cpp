class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int ans=0;
        int n=citations.size();
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=n-i){
                ans=max(n-i,ans);
            }
        }
        return ans;
    }
    /*
    0,1,3,6,5
    */
};