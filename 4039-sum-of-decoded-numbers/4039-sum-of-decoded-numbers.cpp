class Solution {
public:
    const int mod=1e9+7;
   long long powerMod(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            long long w=nums[i]%10;
            long long d=nums[i]/10;
            string s = to_string(d);
            long long base = stoll(s.substr(0, w));
            long long p = stoll(s.substr(w));

            ans = (ans + powerMod(base, p, mod)) % mod;
        }
        return ans;
    }
};