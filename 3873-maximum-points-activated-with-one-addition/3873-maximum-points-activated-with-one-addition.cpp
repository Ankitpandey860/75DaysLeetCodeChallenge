class Solution {
public:
    vector<int> parent, size;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int i,int j){
        int r1=find(i),r2=find(j);
        if(r1!=r2){
            if(size[r1]<size[r2]) swap(r1,r2);
            size[r1]+=size[r2];
            parent[r2]=r1;
        }
    }
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n); size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        unordered_map<int, int> xmap, ymap;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            if(xmap.count(x)) unite(i,xmap[x]);
            else xmap[x]=i;
            if(ymap.count(y)) unite(i,ymap[y]);
            else ymap[y]=i;
        }
        int max1=0,max2=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                if(size[i]>max1) {
                    max2=max1;max1=size[i];
                    }
                else if(size[i]>max2){max2=size[i];}
            }
        }
        return max1+max2+1;
    }
};