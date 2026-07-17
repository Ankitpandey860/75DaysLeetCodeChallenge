class Solution {
public:
    int find(int n,vector<int>& par){
        if(par[n]==n) return n;
        return par[n]=find(par[n],par);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& swap) {
        int n=source.size();
        vector<int>par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto it:swap){
            int a=it[0];
            int b=it[1];

            int pa=find(a,par);
            int pb=find(b,par);
            if(pa!=pb){
                par[pa]=pb;

            }
        }
        unordered_map<int, unordered_map<int,int>> mp;
        for(int i=0;i<n;i++){
            int root=find(i,par);
            int num=source[i];
            mp[root][num]++;
        }
        int hd=0;
        for(int i=0;i<n;i++){
            int num=target[i];
            int root=find(i,par);
            auto &s = mp[root];
            if(s.find(num)==s.end()){
                hd++;
                continue;
            }
            if(s[num]<=0){
                hd++;
            }
            s[num]--;
        }
        return hd;
    }
};