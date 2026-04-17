class Solution {
public:
    long long solve(int i,int j,int encCost, int flatCost,vector<int>& prefix){
        int elem=j-i+1;
        //if(elem%2==1) return LLONG_MAX;
        if(i>j) return LLONG_MAX;
        int sen=prefix[j];
        if(i>0){
            sen-=prefix[i-1];
        }
        long long cost;
        if(sen==0){
            cost=flatCost;
        }
        else{
            cost=1ll*sen*elem*encCost;
        }
        long long split=LLONG_MAX;
        if(elem%2==0){
            int mid=elem/2;
            long long temp1=solve(i,i+mid-1,encCost,flatCost,prefix);
            long long temp2=solve(i+mid,j,encCost,flatCost,prefix);
            if(temp1!=LLONG_MAX&&temp2!=LLONG_MAX){
                split=temp1+temp2;
            }
        }
        return min(cost,split);
    }
    /*
    long long solve(int encCost, int flatCost,vector<int>& prefix){
        int n=prefix.size();
        int len=n;
        long long ans=LLONG_MAX;
        
        while(len){
            long long cost=0;
            for(int i=0;i<n;i+=len){
                int sen=prefix[i+len-1];
                if(i>0){
                    sen-=prefix[i-1];
                }
                
                if(sen==0){
                    cost+=flatCost;
                }
                else{
                    cost=cost+sen*len*encCost;
                }
            }
            if(len%2==0){
                len=len/2;
            }
            else{
                len=0;
            }
            if(cost)
                ans=min(ans,cost);
        }
        return ans;
    }*/
    long long minCost(string s, int encCost, int flatCost) {
        int n=s.length();
        vector<int>prefix(n);
        int sen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                sen++;
            }
            prefix[i]=sen;
        }
        return solve(0,n-1,encCost,flatCost,prefix);
    }
};