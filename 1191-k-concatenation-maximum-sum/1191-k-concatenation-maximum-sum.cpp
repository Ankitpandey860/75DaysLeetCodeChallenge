class Solution {
public:
    const int mod=1e9+7;
    int kadane(vector<int>& arr, int k){
        int i=0;
        int n=arr.size();
        long long maxsum=arr[0];
        long long sum=0;
        while(k){
            sum=sum+arr[i];
            if(sum<0){
                sum=0;
            }
            maxsum=max(sum,maxsum);
            if((i+1)%n==0) k--;
            i=(i+1)%n;
        }
        return maxsum%mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum=(sum+arr[i])%mod;
        }
        if(k==1){
            return kadane(arr,1);
        }
        if(sum<0){
            return kadane(arr,2);
        }
        return (kadane(arr,2)+(1ll*(k-2)*sum)%mod)%mod;
    }
};