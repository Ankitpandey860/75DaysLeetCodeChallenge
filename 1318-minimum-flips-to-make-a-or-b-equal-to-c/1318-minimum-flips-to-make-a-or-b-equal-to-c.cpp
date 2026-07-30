class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        int i=1;
        int maxi=max(a,max(b,c));
        while(i<=maxi){
            bool ao=a&i;
            bool bo=b&i;
            bool co=c&i;
            if(co){
                if(ao==0&&bo==0) cnt++;
            }else{
                cnt+=ao;
                cnt+=bo;
            }
            i=i<<1;
        }
        return cnt;
    }
};