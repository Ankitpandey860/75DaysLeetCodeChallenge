class Solution {
public:
    
    int shortestPathAllKeys(vector<string>& grid) {
        int r,c;
        int n=grid.size();
        int m=grid[0].size();
        int key=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    r=i;
                    c=j;
                }
                else if(grid[i][j]>='a'&&grid[i][j]<='z'){
                    key++;
                }
            }
        }
        int mask=1<<key;
        mask-=1;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        //step,i,j,mask
        using p=tuple<int,int,int,int>;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,r,c,0});
        vector<vector<vector<int>>>dis(n,vector<vector<int>>(m,vector<int>(mask+1,INT_MAX)));
        dis[r][c][0]=0;
        while(!pq.empty()){
            auto [step,i,j,msk]=pq.top();
            pq.pop();
            if(msk==mask) return step;
            if(step>dis[i][j][msk]) continue;
            dis[i][j][msk]=step;
            for(auto it:dir){
                int nr=i+it[0];
                int nc=j+it[1];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){

                    if(grid[nr][nc]=='.'||grid[nr][nc]=='@'){
                        if(dis[nr][nc][msk]>(step+1)){
                            pq.push({step+1,nr,nc,msk});
                            dis[nr][nc][msk]=step+1;
                        }
                    }
                    else if(grid[nr][nc]<='z'&&grid[nr][nc]>='a'){
                        int idx=grid[nr][nc]-'a';
                        int temp=msk|(1<<idx);
                        if(dis[nr][nc][temp]>(step+1)){
                            pq.push({step+1,nr,nc,temp});
                            dis[nr][nc][temp]=(step+1);
                        }
                    }
                    else if(grid[nr][nc]<='Z'&&grid[nr][nc]>='A'){
                        int idx=grid[nr][nc]-'A';
                        int allow=msk&(1<<idx);
                        if(allow!=0){
                            if(dis[nr][nc][msk]>(step+1)){
                                pq.push({step+1,nr,nc,msk});
                                dis[nr][nc][msk]=(step+1);
                            }
                        }
                        
                    }
                }
            }
        }
        return -1;

    }
};