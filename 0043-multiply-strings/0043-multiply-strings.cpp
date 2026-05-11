class Solution {
public:
    void mul(vector<int>& fst,vector<int>& scd,vector<int>& ans){
        reverse(fst.begin(),fst.end());
        reverse(scd.begin(),scd.end());
        for(int i=0;i<fst.size();i++){
            int mul=fst[i];
            for(int j=0;j<scd.size();j++){
                int sum=mul*scd[j]+ans[i+j];
                int carry=sum/10;
                int val=sum%10;
                ans[i+j]=val;
                ans[i+j+1]+=carry;
            }
        }
    }
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int>ans(n+m,0);
        vector<int>fst,scd;
        for(auto ch:num1){
            fst.push_back(ch-'0');
        }
        for(auto ch:num2){
            scd.push_back(ch-'0');
        }
        mul(fst,scd,ans);
        reverse(ans.begin(),ans.end());
        while(ans.size()>1&&ans[0]==0){
            ans.erase(ans.begin());
        }
        string ansstr="";
        for(int i=0;i<ans.size();i++){
            ansstr+=ans[i]+'0';
        }
        return ansstr;
    }
};