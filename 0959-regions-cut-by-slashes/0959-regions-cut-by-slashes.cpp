class Solution {
public:
    int find(int a,vector<int>& parent){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a],parent);
    }
    void uni(int a,int b,vector<int>& parent,vector<int>& rank,int &count){
        int pa=find(a,parent);
        int pb=find(b,parent);
        if(pa!=pb){
            if(rank[pa]>rank[pb]){
                parent[pb]=pa;
                rank[pa]+=rank[pb];
            }
            else{
                parent[pa]=pb;
                rank[pb]+=rank[pa];
            }
        }
        else{
            count++;
        }

    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int dots=(n+1);
        vector<int>parent(dots*dots),rank(dots*dots,0);
        for(int i=0;i<parent.size();i++) {parent[i]=i;rank[i]=1;}
        int ans=0;
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0||j==0||i==dots-1||j==dots-1){
                    int cell=i*dots+j;
                    uni(0,cell,parent,rank,ans);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    int cell1=i*dots+j+1;
                    int cell2=(i+1)*dots+j;
                    uni(cell1,cell2,parent,rank,ans);
                }
                else if(grid[i][j]=='\\'){
                    int cell1=i*dots+j;
                    int cell2=(i+1)*dots+j+1;
                    uni(cell1,cell2,parent,rank,ans);
                }
            }
        }
        return ans;
    }
};