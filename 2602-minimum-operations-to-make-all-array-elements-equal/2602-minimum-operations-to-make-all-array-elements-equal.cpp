class Solution {
public:
    int lessidx(vector<int>& nums, int req) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < req) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int highidx(vector<int>& nums, int req) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > req) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<long long>prefix(n),suffix(n),ans(m);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int req=queries[i];
            long long temp=0;
            int li=lessidx(nums,req);
            int hi=highidx(nums,req);
            if(li!=-1){
                long long shouldbe=(1ll*li+1)*req;
                long long is=prefix[li];
                temp+=shouldbe-is;
            }
            if(hi!=n){
                long long shouldbe=(1ll*n-hi)*req;
                long long is=suffix[hi];
                temp+=is-shouldbe;
            }
            ans[i]=temp;
        }
        return ans;
    }
};