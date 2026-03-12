class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>nums2;
        for(int i=0;i<nums.size();i++){
            nums2.push_back({nums[i],i});
        }
        sort(nums2.begin(),nums2.end());
        int i=0;
        int k=nums2.size()-1;
        
        vector<int>ans;
        while(i<k){
            int sum=nums2[i].first+nums2[k].first;
            if (sum == target) {
                ans.push_back(nums2[i].second); 
                ans.push_back(nums2[k].second); 
                return ans;
            }
            if(sum>target){
                k--;
            }
            else{
                i++;
            }
            
        }
        
        
        return ans;
    }
};