class Solution {
public:
    int check(int i,int j,string& s){
        int n=s.length();
        int turn=(n+1)/2;
        int cnt=0;
        while(turn--){
            char l=s[i];
            char r=s[j];
            if(l>r) swap(l,r);
            int ltr=r-l;
            int rtl='z'-r+l-'a'+1;
            cnt+=min(ltr,rtl);
            i=(i-1+n)%n;
            j=(j+1)%n;
        }
        return cnt;
    }
    int minOperations(string s) {
        int n=s.length();
        int ans=INT_MAX;
        if(n%2==0){
            for(int i=0;i<n;i++){
                int curr = check(i,(i+1)%n,s);

                int center = n/2 - 1;
                int cst = (i-center+n)%n;
                ans = min(ans, curr+cst);
            }
        }
        else{
            int center = n/2;

            for(int i=0;i<n;i++){
                int curr = check(i,i,s);

                int cst =(i-center+n)%n;

                ans = min(ans, curr+cst);
            }
        }
        return ans;
    }
};


