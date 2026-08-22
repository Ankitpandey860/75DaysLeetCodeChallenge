class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int temp=n;
        while(n>0){
            int dig=n%10;
            sum+=dig;
            prod*=dig;
            n/=10;
        }
        sum+=prod;
        if(sum!=0&&temp%sum==0) return true;
        return false;
    }
};