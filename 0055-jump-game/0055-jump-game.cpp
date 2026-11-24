class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            jump=max(jump-1,nums[i]);
            if(jump<=0&&i<n-1) return false;
        }
        return true;
    }
};