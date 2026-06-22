class Solution {
public:
    void prime(int n,unordered_set<int>& st){
        int i=2;
        while(i<=n){
            if(n%i==0){
                st.insert(i);
                while(n%i==0){
                    n/=i;
                }
            }
            i++;
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums){
            prime(it,st);
        }
        return st.size();
    }
};