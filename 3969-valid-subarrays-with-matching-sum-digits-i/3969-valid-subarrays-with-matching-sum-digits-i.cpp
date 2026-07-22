class Solution {
public:
    bool cndn(long long n,int& x){
        if(n%10!=x) return false;
        while(n>9){
            n/=10;
        }
        return n==x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            long long temp=0;
            for(int j=i;j<n;j++){
                temp+=nums[j];
                if(cndn(temp,x)) ans++;
                cnt++;
            }
        }
        cout<<cnt;
        return ans;
    }
};