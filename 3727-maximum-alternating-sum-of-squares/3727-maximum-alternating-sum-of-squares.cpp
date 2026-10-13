class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int pos=(n+1)/2;
        int neg=n-pos;
        priority_queue<int>pq;
       
        for(int i=0;i<n;i++){
            pq.push(abs(nums[i]));
        }
        long long ans=0;
        for(int i=0;i<pos;i++){
            long long curr=pq.top();
            pq.pop();
            ans+=(curr*curr);
        }
        while(!pq.empty()){
            long long curr=pq.top();
            pq.pop();
            ans-=(curr*curr);
        }
        return ans;
    }
};