class Solution {
public:
    string ans="";
    void expand(string& s,int i,int j){
        while(i>=0&&j<s.length()){
            if(s[i]!=s[j]) break;
            i--;
            j++;
        }
        if(ans.length()<(j-i)){
            ans=s.substr(i+1,j-i-1);
        }
    }
    string longestPalindrome(string s) {
        int n=s.length();
       //string ans="";
        for(int i=0;i<n;i++){
            expand(s,i,i+1);
            expand(s,i,i);
        }
        return ans;
    }
};