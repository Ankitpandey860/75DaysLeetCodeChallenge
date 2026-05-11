class Solution {
public:
    bool dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& board, string& word,int i2){
        if(i2==word.length()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        if(board[i][j]==word[i2]){
            if(i2+1==word.size()) return true;
            bool ans=false;
            for(auto it:dir){
                int nr=i+it[0];
                int nc=j+it[1];
                if(nr>=0&&nr<board.size()&&nc>=0&&nc<board[0].size()&&!vis[nr][nc]){
                    vis[nr][nc]=true;
                    ans=ans|dfs(nr,nc,vis,board,word,i2+1);
                    vis[nr][nc]=false;
                }
            }
            return ans;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    ans=ans|dfs(i,j,vis,board,word,0);
                    vis[i][j]=false;
                }
                    
            }
        }
        return ans;
    }
};