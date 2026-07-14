class Solution {
public:
    string add(string s){
        int i=s.length()-1;
        while(i>=0&&s[i]=='1'){
            s[i]='0';
            i--;
        }
        if(i>=0){
            s[i]='1';
            return s;
        }
        return '1'+s;
    }
    int numSteps(string s) {
        int cnt=0;
        while(s.length()>1){
            int idx=s.length()-1;
            if(s[idx]=='1'){
                s=add(s);
            }
            else{
                s.pop_back();
            }
            cnt++;
        }
        return cnt;
    }
};