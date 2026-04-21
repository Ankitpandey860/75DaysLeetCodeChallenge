class Solution {
public:
    const int mod=1e9+7;
    int power(long long a, long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res*a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return res;
    }
    int sumOfNumbers(int l, int r, int k) {
        long long cnt=r-l+1;
        long long sum = (cnt * 1ll * (l + r) % mod) * power(2, mod-2) % mod;

        long long part1 = power(cnt, k-1);

        long long geometric = (power(10, k) - 1 + mod) % mod;
        long long inv9 = power(9, mod-2);
        geometric = geometric * inv9 % mod;

        return sum % mod * part1 % mod * geometric % mod;
    }
};