class Solution {
public:
    int maxDepth(string s) {
        int l=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')'){
                l--;
            }
            ans=max(ans,l);

        }
        return ans;
    }
};