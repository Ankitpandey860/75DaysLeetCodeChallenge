class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        vector<vector<int>>vis(8,vector<int>(8,INT_MAX));
        using p=tuple<int,int,int>;
        queue<p>q;
        int u=source[0]-1;
        int v=source[1]-1;
        int ti=target[0]-1;
        int tj=target[1]-1;
        q.push({0,u,v});
        vis[u][v]=0;
        while(!q.empty()){
            auto [step,u,v]=q.front();
            q.pop();
            if(vis[u][v]<step) continue;
            if(u==ti&&v==tj) return step;
            //up right
            int i=u-1;
            int j=v+1;
            while(i>=0&&j<8){
                if(vis[i][j]>step+1){
                    q.push({step+1,i,j});
                    vis[i][j]=step+1;
                }
                i--;
                j++;
            }
            //up left
            i=u-1;
            j=v-1;
            while(i>=0&&j>=0){
                if(vis[i][j]>step+1){
                    q.push({step+1,i,j});
                    vis[i][j]=step+1;
                }
                i--;
                j--;
            }
            //down left
            i=u+1;
            j=v-1;
            while(i<8&&j>=0){
                if(vis[i][j]>step+1){
                    q.push({step+1,i,j});
                    vis[i][j]=step+1;
                }
                i++;
                j--;
            }

            //down right
            i=u+1;
            j=v+1;
            while(i<8&&j<8){
                if(vis[i][j]>step+1){
                    q.push({step+1,i,j});
                    vis[i][j]=step+1;
                }
                i++;
                j++;
            }
            
        }
        return -1;
    }
};