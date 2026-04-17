class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') continue;
                for(int curr=1;curr<=9;curr++){
                    bool poss=true;
                    char ch=curr+'0';
                    for(int cr=0;cr<9;cr++){
                        if(board[cr][j]==ch||board[i][cr]==ch){
                            poss =false;
                        }
                    }
                    for(int cr=i/3*3;cr<(i/3*3)+3;cr++){
                        for(int cj=j/3*3;cj<(j/3*3)+3;cj++){
                            if(board[cr][cj]==ch){
                                poss =false;
                            }
                        }
                    }
                    if(poss){
                        board[i][j]=ch;
                        bool iscorr=solve(board);
                        if(!iscorr){
                            board[i][j]='.';
                        }
                        else{
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};