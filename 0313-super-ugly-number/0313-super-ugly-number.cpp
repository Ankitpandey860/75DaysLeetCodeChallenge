class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int i=0;
         priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        while(!pq.empty()&&i<n){
            long long curr=pq.top();
            i++;
            if(i==n) return curr;
            pq.pop();
            for(int it:primes){
                //if(st.size()+i<n)
                pq.push(1ll*curr*it);
            }
            while(!pq.empty()&&pq.top()==curr){
                pq.pop();
            }
        }
        return i;
    }
};