class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int,vector<int>>mp;
        int sum=0,one=0,zero=0;
        mp[0].push_back(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                sum++;
            }
            else{
                sum--;
            }
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum][0]);
            }
            if(mp.count(sum+2)){
                for(auto it:mp[sum+2]){
                    int len=i-it;
                    int ones=(len-2)/2;
                    if(ones<one){
                        ans=max(ans,len);
                    }
                }
            }
            if(mp.count(sum-2)){
                for(auto it:mp[sum-2]){
                    int len=i-it;
                    int zeroes=(len-2)/2;
                    if(zeroes<zero){
                        ans=max(ans,len);
                    }
                }
            }
            mp[sum].push_back(i);
        }
        return ans;
        
        
    }
};