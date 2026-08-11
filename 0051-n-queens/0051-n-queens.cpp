class Solution {
public:
    bool dig(vector<vector<char>>& board, int r, int c) {
    int n = board.size();


        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return true; 
        }

  
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return true; 
        }

        return false; 
    }

    vector<string> conv(vector<vector<char>>& board){
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            string s="";
            for(auto it:board[i]){
                s+=it;
            }
            ans.push_back(s);
        }
        return ans;
    }
    void solve(vector<vector<char>>& board,vector<bool>& row,vector<bool>& col,int i,int &n,vector<vector<string>>& ans){
        if(i>=n){
            vector<string> temp=conv(board);
            ans.push_back(temp);
            return ;
        }
        for(int c=0;c<n;c++){
            if(col[c]==false&&dig(board,i,c)==false){
                col[c]=true;
                board[i][c]='Q';
                solve(board,row,col,i+1,n,ans);
                col[c]=false;
                board[i][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>row(n),col(n);
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        solve(board,row,col,0,n,ans);
        return ans;
    }
};