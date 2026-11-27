class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        int j=0;
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            bool all=true;
            for(int j=1;j<strs.size();j++){
                int k=0;
                while(k<=i){
                    if(strs[0][k]==strs[j][k]){
                        k++;
                    }
                    else{
                        all=false;
                        break;
                    }
                }
            }
            if(all) ans+=strs[0][i];
            else return ans;
        }
        return ans;
    }
};