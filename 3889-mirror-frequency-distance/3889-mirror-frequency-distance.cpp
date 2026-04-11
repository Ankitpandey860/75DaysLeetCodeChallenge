class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(char ch = 'a'; ch <= 'm'; ch++){
            char mirror = 'a' + ('z' - ch);
            count += abs(mp[ch] - mp[mirror]);
        }
         for(char ch = '0'; ch <= '4'; ch++){
            char mirror = '0' + ('9' - ch);
            count += abs(mp[ch] - mp[mirror]);
        }
        return count;
    }
};