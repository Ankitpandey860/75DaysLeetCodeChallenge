class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0) return 1;
        vector<double>p(n+1,0.0);
        p[0]=1;
        double curr=1.00000;
        for(int i=1;i<=n;i++){
            p[i]=curr/maxPts;
            if(i<k)
                curr+=p[i];
            if(i-maxPts>=0&&i-maxPts<k)
                curr-=p[i-maxPts];
        
        }
        return accumulate(begin(p)+k,end(p),0.0);
    }
};