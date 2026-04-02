class Solution {
public:
    bool pal(string& s,int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(s[i]==s[j]&&pal(s,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};