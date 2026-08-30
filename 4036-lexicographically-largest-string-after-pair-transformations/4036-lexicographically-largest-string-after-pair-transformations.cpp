class Solution {
public:
    string solve(int n){
        if(n==0) return "";
        if(n==1) return "a";
        int i=0;
        while(i<25&&(1<<(i+1))<=n){
            i++;
        }
        int rem=n-(1<<i);
        char ch='a';
        ch=ch+i;
        return ch+solve(rem);
    }
    vector<string> largestString(vector<int>& nums) {
        int n=nums.size();
         vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=solve(nums[i]);
        }
        return ans;
    }
};
