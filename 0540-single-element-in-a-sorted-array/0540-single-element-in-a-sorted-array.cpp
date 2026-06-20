class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        int i=0;
        int j=nums.size()-1;
        if(nums[j]!=nums[j-1]){
            return nums[j];
        }
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid]==nums[mid-1]){
                if((mid-i+1)%2==0){
                    i=mid+1;
                }
                else{
                    j=mid-2;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if((j-mid+1)%2==0){
                    j=mid-1;
                }
                else{
                    i=mid+2;
                }
            }
            
            //cout<<"i "<<i<<" j "<<j<<" mid "<<mid<<endl;
        }
        return i;*/
        int elem=nums[0];
        for(int i=1;i<nums.size();i++){
            elem=elem^nums[i];
        }
        return elem;
    }
};