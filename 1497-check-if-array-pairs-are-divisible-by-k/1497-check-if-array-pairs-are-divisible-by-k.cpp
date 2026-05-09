class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int curr=((arr[i] % k) + k) % k;
            mp[curr]++;
        }
        for(int i=0;i<arr.size();i++){
            int curr=((arr[i] % k) + k) % k;
            //int req=(k-curr)%k;
            
            if(mp[curr] != mp[(k-curr)%k])
                return false;
        }
        return mp[0] % 2 == 0;
    }
};