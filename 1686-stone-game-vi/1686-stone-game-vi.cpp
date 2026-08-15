class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        return a.first+a.second>b.first+b.second;
    }
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            auto p=make_pair(aliceValues[i],bobValues[i]);
            temp[i]=p;
        }
        sort(temp.begin(),temp.end(),cmp);
        int diff=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                diff+=temp[i].first;
            }
            else{
                diff-=temp[i].second;
            }
        }
        if(diff==0) return 0;
        if(diff<0) return -1;
        return 1;
    }
};