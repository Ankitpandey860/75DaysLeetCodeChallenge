class Solution {
public:
    const int mod=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int lessa=0;
        int atb=0;
        int moreb=0;
        long long swap=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a){
                swap+=moreb+atb;
                lessa++;
            } 
            else if(nums[i]>b){
                moreb++;
            }
            else{
                swap+=moreb;
                atb++;
            } 
            swap%=mod;
        }
        return swap;
    }
};