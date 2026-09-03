class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int maxodd=INT_MIN;
        int minodd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1){
                maxodd=max(maxodd,nums1[i]);
                minodd=min(minodd,nums1[i]);
            }
        }
        if(maxodd==INT_MIN&&minodd==INT_MAX){
            return true;
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
               if((nums1[i]-minodd)<1){
                   return false;
               }
            }
        }
        return true;
    }
};