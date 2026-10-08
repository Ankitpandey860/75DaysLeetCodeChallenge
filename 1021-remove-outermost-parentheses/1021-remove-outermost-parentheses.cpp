class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==1&&s[i]=='('){
                s[i]='1';
            }
            if(count==0&&s[i]==')'){
                s[i]='1';
            }
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]!='1'){
                ans+=s[i];
            }
        }
        return ans;
    }
};