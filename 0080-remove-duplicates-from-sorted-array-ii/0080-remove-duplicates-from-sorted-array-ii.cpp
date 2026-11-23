class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int j=2;
        while(j<n){
            if(nums[j]==nums[i]&&nums[i-1]==nums[j]){
                j++;
            }
            else{
                if(i+1<n)
                swap(nums[i+1],nums[j]);
                i++;
                j++;
            }
        }
        return min(i+1,n);
    }
};