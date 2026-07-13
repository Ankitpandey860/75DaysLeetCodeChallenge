class Solution {
public:
    int find(int n,vector<int>& parent){
        if(parent[n]==n) return n;
        parent[n]=find(parent[n],parent);
        return parent[n];
    }
    bool uni(int x,int y,vector<int>& parent,vector<int>& rank){
        int lx=find(x,parent);
        int ly=find(y,parent);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                parent[ly]=lx;
                rank[lx]+=rank[ly];
            }
            else{
                parent[lx]=ly;
                rank[ly]+=rank[lx];
            }
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parenta(n+1),ranka(n+1),parentb(n+1),rankb(n+1);
        sort(edges.begin(),edges.end());
        reverse(edges.begin(),edges.end());
        for(int i=1;i<=n;i++){
            parenta[i]=i;
            parentb[i]=i;
            ranka[i]=1;
            rankb[i]=1;
        }
        int mergeda=1,mergedb=1,remove=0;
        for(auto it:edges){
            if(it[0]==3){
                bool tempa=uni(it[1],it[2],parenta,ranka);
                bool tempb=uni(it[1],it[2],parentb,rankb);
                if(tempa==false&&tempb==false) remove++;
                if(tempa) mergeda++;
                if(tempb) mergedb++;
            }
            else if(it[0]==2){
                bool tempb=uni(it[1],it[2],parentb,rankb);
                if(tempb) mergedb++;
                else remove++;
            }
            else{
                bool tempa=uni(it[1],it[2],parenta,ranka);
                if(tempa) mergeda++;
                else remove++;
            }
        }
        if(mergeda!=n||mergedb!=n) return -1;
        return remove;
    }
};