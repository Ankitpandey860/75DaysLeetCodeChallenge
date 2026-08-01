class Solution {
public:
    bool valid(int i,int j){
        if(i<0||i>=2||j<0||j>=3) return false;
        return true;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        using p=tuple<int,vector<vector<int>>,int,int>;
        queue<p>pq;
        int r,c;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>>req={{1,2,3},{4,5,0}};
        map<vector<vector<int>>,int>dis;
        pq.push({0,board,r,c});
        dis[board]=0;
        while(!pq.empty()){
            auto [step,curr,r,c]=pq.front();
            pq.pop();
            if(req==curr) return step;
            if(dis.find(curr)!=dis.end()&&step > dis[curr]) continue;
            for(auto it:dir){
                int nr=r+it[0];
                int nc=c+it[1];
                if(valid(nr,nc)){
                    vector<vector<int>>temp=curr;
                    swap(temp[r][c],temp[nr][nc]);
                    if(dis.find(temp)==dis.end()||dis[temp]>step+1){
                        dis[temp]=step+1;
                        pq.push({step+1,temp,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};