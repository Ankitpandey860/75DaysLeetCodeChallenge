class Solution {
public:
    int solve(int n,int i){
        if(i>n) return 0;
        int ans=1;
        for(int j=0;j<i;j++){
            if(j==0) ans*=9;
            else{
                ans*=(10-j);
            }
        }
        return ans+solve(n,i+1);
    }
    int countNumbersWithUniqueDigits(int n) {
        //if(n==0) return 1;
        return solve(n,0);
    }
};