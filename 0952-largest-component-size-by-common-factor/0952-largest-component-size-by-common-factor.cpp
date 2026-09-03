class Solution {
public:
    vector<int> factors(int n){
        vector<int>ans;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                while(n%i==0){
                    n/=i;
                }
                    
            }
        }
        if(n>1)
            ans.push_back(n);
        return ans;
    }
    int find(vector<int>& par,int a){
        if(a==par[a]) return a;
        return par[a]=find(par,par[a]);
    }
    void uni(vector<int>& par,vector<int>& rank,int &a,int& b){
        int pa=find(par,a);
        int pb=find(par,b);
        if(pa==pb) return;
        if(rank[pa]>rank[pb]){
            rank[pa]+=rank[pb];
            par[pb]=pa;
        }else{
            rank[pb]+=rank[pa];
            par[pa]=pb;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        unordered_map<int,list<int>>factortonum;
        for(auto &it:nums){
            vector<int>fac=factors(it);
            for(auto it2:fac){
                factortonum[it2].push_back(it);
            }
        }
        
        vector<int>rank(1e5+3,1),par(1e5+3);
        for(int i=0;i<par.size();i++){
            par[i]=i;
        }
        for(auto &it:factortonum){
            vector<int>vals;
            for(auto& it2:it.second){
                vals.push_back(it2);
            }
            for(int i=1;i<vals.size();i++){
                int pu=find(par,vals[i]);
                int pv=find(par,vals[i-1]);
                if(pu!=pv)
                uni(par,rank,vals[i],vals[i-1]);
            }
        }
        int ans=1;
        for(auto it:nums){
            int pu=find(par,it);
            ans=max(ans,rank[pu]);
        }
        return ans;
    }
};