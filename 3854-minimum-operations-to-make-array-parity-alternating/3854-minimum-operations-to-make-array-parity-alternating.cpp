class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int ans=INT_MAX;
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(i&1&&!(nums[i]&1)){
                cnt1++;
            }
            else if(!(i&1)&&(nums[i]&1)){
                cnt1++;
            }
        }
        ans=min(ans,cnt1);
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(i&1&&(nums[i]&1)){
                cnt2++;
            }
            else if(!(i&1)&&!(nums[i]&1)){
                cnt2++;
            }
        }
        ans=min(ans,cnt2);
        auto result =minmax_element(nums.begin(), nums.end());
        int mini=*result.first;
        int maxi=*result.second;
        int mini2=mini;
        int maxi2=maxi;
        vector<int>v1=nums;
        vector<int>v2=nums;
        int ans2=INT_MAX;
        if(ans==cnt1){
            for(int i=0;i<nums.size();i++){
                if(i&1&&!(nums[i]&1)){
                    if(v1[i]==maxi){
                        v1[i]--;
                    }
                    else if(v1[i]==mini)v1[i]++;
                }
                else if(!(i&1)&&(nums[i]&1)){
                    if(v1[i]==maxi){
                        v1[i]--;
                    }
                    else if(v1[i]==mini)v1[i]++;
                }
            }
            auto res1=minmax_element(v1.begin(), v1.end());
            ans2=min(ans2,*res1.second-*res1.first);
        }
        if(ans==cnt2){
            for(int i=0;i<nums.size();i++){
                if(i&1&&(nums[i]&1)){
                    if(v2[i]==maxi){
                        v2[i]--;
                    }
                    else if(v2[i]==mini)v2[i]++;                }
                else if(!(i&1)&&!(nums[i]&1)){
                    if(v2[i]==maxi){
                        v2[i]--;
                    }
                    else if(v2[i]==mini)v2[i]++;
                }
            }
            auto res2=minmax_element(v2.begin(), v2.end());
            ans2=min(ans2,*res2.second-*res2.first);
        }
        return {ans,ans2};
    }
};