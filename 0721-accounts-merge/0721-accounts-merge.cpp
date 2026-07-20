class Solution {
public:
    int find(int u,vector<int>& p){
        if(p[u]==u) return u;
        return p[u]=find(p[u],p);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int>par(10001);
        for(int i=0;i<10001;i++){
            par[i]=i;
        }
        unordered_map<string,int>euid;
        unordered_map<string,string>etn;
        int uid=0;
        for(auto& account:accounts){
            string name="";
            for(auto& email:account){
                if(name==""){
                    name=email;
                    continue;
                }
                if(euid.find(email)==euid.end()){
                    euid[email]=uid;
                    uid++;
                }
                if(etn.find(email)==etn.end()){
                    etn[email]=name;
                }
                int uid1=euid[account[1]];
                int curr=euid[email];
                int p1=find(uid1,par);
                int pc=find(curr,par);
                if(p1!=pc){
                    par[p1]=pc;
                }
            }
        }
        unordered_map<int,list<string>>pte;
        for(auto& it:etn){
            string email=it.first;
            int uid=euid[email];
            int p=find(uid,par);
            pte[p].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto& it:pte){
            //sort(it.second.begin(),it.second.end());
            it.second.sort();
            string email=*it.second.begin();
            string name=etn[email];
            vector<string>tp;
            tp.push_back(name);
            for(auto& it2:it.second){
                tp.push_back(it2);
            }
            ans.push_back(tp);
        }
        return ans;
    }
};