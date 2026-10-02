class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int dig=(sum+8)/9;
        if(dig>num) return "";
        string ans="";
        while(sum>0&&num>0){
            if(sum>=9){
                ans+='9';
                sum-=9;
                num--;
            }
            else{
                ans+=to_string(sum);
                sum=0;
                num--;
            }
        }
        while(num){
            ans+='0';
            num--;
        }
        return ans;
    }
};