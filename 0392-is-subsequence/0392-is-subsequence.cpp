class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        int x=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[x]){
                x++;
            }
            if(x==s.length()){
                return true;
            }
        }
        return false;
    }
};