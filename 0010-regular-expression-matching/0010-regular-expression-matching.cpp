class Solution {
public:
    int solve(string& A,string& B,int i,int j){
        if(i==A.length()&&j==B.length()) return true;
        if(j==B.length()) return false;
        if(i==A.length()){
            if(j+1<B.length()&&B[j+1]=='*')
                return solve(A,B,i,j+2);
            return false;
        }
        
        if(j+1<B.length()&&B[j+1]=='*'){
            bool skip=false;
            bool take=false;
            if(A[i]==B[j]||B[j]=='.'){
                take=solve(A,B,i+1,j);
            }
            skip=solve(A,B,i,j+2);
            return skip||take;
        }
        else if(B[j]=='.'){
            return solve(A,B,i+1,j+1);
        }
        else if(A[i]==B[j]){
            return solve(A,B,i+1,j+1);
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};