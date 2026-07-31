class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y;
        int cnt=0;
        while(temp>0){
            if(temp%2==1)cnt++;
            temp/=2;
        }
        return cnt;
    }
};