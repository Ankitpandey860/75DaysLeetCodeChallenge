class Solution {
public:
    pair<vector<int>, vector<int>> get_next_indices(vector<int>& arr) {
        int n = arr.size();
        vector<int> big(n, n);   // Odd jump next indices (default to n)
        vector<int> small(n, n); // Even jump next indices (default to n)

        // 1. Calculate 'big' (Odd jumps: smallest value >= arr[i])
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort indices primarily by value ascending, secondarily by index ascending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] < arr[b];
            return a < b;
        });

        // Monotonic stack to find next greater index in sorted array
        stack<int> st;
        for (int i : idx) {
            while (!st.empty() && st.top() < i) {
                big[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // 2. Calculate 'small' (Even jumps: largest value <= arr[i])
        // Sort indices primarily by value descending, secondarily by index ascending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return arr[a] > arr[b];
            return a < b;
        });

        while (!st.empty()) st.pop(); // Clear stack

        for (int i : idx) {
            while (!st.empty() && st.top() < i) {
                small[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return {big, small};
    }
    int solve(int i,vector<int>& arr,vector<int>& small,vector<int>& big,int par,vector<vector<int>>& dp){
        if(i==arr.size()-1) return 1;
        if(dp[i][par]!=-1) return dp[i][par];
        if(par){   // odd jumppp 
            int nxtidx=big[i];
            if(nxtidx==arr.size()) return 0;
            return dp[i][par]=solve(nxtidx,arr,small,big,par^1,dp);
        }
        else{
            int nxtidx=small[i];
            if(nxtidx==arr.size()) return 0;
            return dp[i][par]=solve(nxtidx,arr,small,big,par^1,dp);
        }
    }
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int>small(n),big(n);
        auto temp=get_next_indices(arr);
        small=temp.second;
        big=temp.first;
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            ans+=solve(i,arr,small,big,1,dp);
        }
        return ans;
    }
};