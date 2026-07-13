class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        if(n==1||m==1){
            if(k!=1){
                return {};
            }
            return vector<string>(n,string(m,'.'));
        }
        vector<string>ans (n,string(m,'#'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==m-1) ans[i][j]='.';
            }
        }
        if(k==1) return ans;
        if(k==2){
            ans[1][m-2]='.';
            return ans;
        }
        if(k==3){
            if(n==2&&m==2) return {};
            ans[1][m-2]='.';
            if(m>=3){
                ans[1][m-3]='.';
            }
            else{
                ans[2][m-2]='.';
            }
            return ans;
        }
        if(n==2){
            if(m<4) return {};
            ans[1][m-2]=ans[1][m-3]=ans[1][m-4]='.';
            return ans;
        }
        else if(m==2){
            if(n<4){
                return {};
            }
            ans[1][0]=ans[2][0]=ans[3][0]='.';
            return ans;
        }
        
        ans[0][m-1]='#';
        ans[1][m-2]='.';
        ans[1][m-3]='.';
        ans[2][m-2]='.';
        return ans;
    }
};