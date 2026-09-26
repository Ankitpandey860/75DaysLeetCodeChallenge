class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto &it:knowledge){
            mp[it[0]]=it[1];
        }
        bool open=false;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open=true;
            }
            else if(s[i]==')'){
                open=false;
                if(mp.find(temp)!=mp.end()){
                    ans+=mp[temp];
                }
                else{
                    ans+="?";
                }
                temp.clear();
            }
            else{
                if(open){
                    temp+=s[i];
                }
                else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};