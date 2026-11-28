class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0;
        int end=numbers.size()-1;
        vector<int>ans(2);
        while(st<end){
            int sum=numbers[st]+numbers[end];
            if(sum==target){
                
                ans[0]=st+1;
                ans[1]=end+1;
                return ans;
            }
            else if(sum>target){
                end--;
            }
            else{
                st++;
            }
        }
        return ans;
    }
};