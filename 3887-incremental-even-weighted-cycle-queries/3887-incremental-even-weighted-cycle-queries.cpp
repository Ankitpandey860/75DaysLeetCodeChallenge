class Solution {
public:
    vector<int>parent,size,parity;
    void dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        parity.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int parentfind(int i){
        if(parent[i]==i) return i;
        //return parentfind(parent[i]);
        int old=parent[i];
        parent[i]=parentfind(parent[i]);
        parity[i]^=parity[old];
        return parent[i];
    }
    bool unite(int u,int v,int w){
        int p1=parentfind(u);
        int p2=parentfind(v);
        if(p1==p2){
            if((parity[u]^parity[v])==w) return true;
            else return false;
        }
        if(size[p1]<size[p2]){
            parent[p1]=p2;
            parity[p1]=parity[v]^parity[u]^w;
            size[p2]+=size[p1];
        }
         else{

            parent[p2]=p1;
            parity[p2]=parity[v]^parity[u]^w;
            size[p1]+=size[p2];
        }

        return true;
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        dsu(n);
        int ans=0;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(unite(u,v,w)){
                ans++;
            }
        }
        return ans;
    }
};