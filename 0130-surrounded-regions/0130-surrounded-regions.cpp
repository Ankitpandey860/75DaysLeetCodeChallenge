class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>safe(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
            }
        }
        int moves[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            safe[r][c]=true;
            q.pop();
            for(auto it:moves){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr<n&&nr>=0&&nc<m&&nc>=0&&!safe[nr][nc]&&board[nr][nc]=='O'){
                    safe[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!safe[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};