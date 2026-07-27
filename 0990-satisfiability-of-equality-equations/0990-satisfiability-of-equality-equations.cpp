class Solution {
public:
    int find(int a,vector<int>& par){
        if(par[a]==a) return a;
        return par[a]=find(par[a],par);
    }
    void merge(int a,int b,vector<int>& par,vector<int>& rank){
        int pa=find(a,par);
        int pb=find(b,par);
        if(pa!=pb){
            if(rank[pa]>rank[pb]){
                par[pb]=pa;
                rank[pa]+=rank[pb];
            }
            else{
                par[pa]=pb;
                rank[pb]+=rank[pa];
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int>par(26),rank(26);
        for(int i=0;i<26;i++){
            par[i]=i;
            rank[i]=1;
        }

        for(auto& it:equations){
            if(it[1]=='='&&it[2]=='='){
                int a=it[0]-'a';
                int b=it[3]-'a';
                merge(a,b,par,rank);
            }
        }
        for(auto& it:equations){
            if(it[1]=='!'){
                int a=it[0]-'a';
                int b=it[3]-'a';
                int pa=find(a,par);
                int pb=find(b,par);
                if(pa==pb) return false;
            }
        }
        return true;
    }
};