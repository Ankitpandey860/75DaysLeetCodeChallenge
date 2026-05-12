class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>left(n),right(n);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                sum+=nums[i];
                left[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i-k];
                left[i]=max(left[i-1],sum);
            }
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+k>=n){
                sum+=nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+k];
                right[i]=max(right[i+1],sum);
            }
        }
        int max=0;
        vector<int>ans;
        int stm=-1;
        for(int i=k-1;i<n-2*k;i++){
            int lft=left[i];
            int rght=right[i+k+1];
            int cnt=0;
            for(int j=i+1;j<i+k+1;j++){
                cnt+=nums[j];
            }
            if(lft+rght+cnt>max){
                max=lft+rght+cnt;
                stm=i+1;
            }
        }
        int reqst=left[stm-1];
        int stf=-1;
        sum=0;
        for(int i=0;i<stm;i++){
            if(i<k){
                sum+=nums[i];
            }
            else{
                sum+=nums[i]-nums[i-k];
            }
            if(sum==reqst){
                stf=i-k+1;
                break;
            }
        }
        sum=0;
        int reqend=right[stm+k];
        int stt=-1;
        sum=0;
        for(int i=stm+k;i<right.size();i++){
            if(i<stm+2*k){
                sum+=nums[i];
            }
            else{
                sum+=nums[i]-nums[i-k];
            }
            if(sum==reqend){
                stt=i-k+1;
                break;
            }
        }
        return {stf,stm,stt};
    } 
};
/*           0  1  2  3  4  5   6  7 
    left    1  3  3  3  8  13  13 13
    right   13 13 13 13 13 13  6  1
    cnt     3  3  3  8
 1  3  5 5   3   5   6
 0  1  2  3   4  5  6
 n=7
 2
 2*/