class Solution {
public:
    void solve(int o,int c,string &s,vector<string>& ans){
        if(o==0&&c==0){
            ans.push_back(s);
        }
        if(o>0){
            s+='(';
            solve(o-1,c,s,ans);
            s.pop_back();
        }
        if(c>o){
             s+=')';
            solve(o,c-1,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solve(n,n,temp,ans);
        return ans;
    }
};