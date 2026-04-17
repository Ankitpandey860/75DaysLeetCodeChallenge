class Solution {
public:
    int minOperations(string s) {
        string temp=s;
        sort(temp.begin(),temp.end());
        if(s==temp) return 0;
        if(s.length()==2) return -1;
        int n=s.length();
        if(s[0]==temp[n-1]&&s[n-1]==temp[0]){
            for(int i=1;i<n-1;i++){
                if(s[i]==temp[0]||s[i]==temp[n-1]) return 2;
            }
            return 3;
        }
        if(s[0]==temp[0]||s[n-1]==temp[n-1]){
            return 1;
        }
        if(s[0]==temp[n-1]||s[n-1]==temp[0]) return 2;
        return 2;
    }
};