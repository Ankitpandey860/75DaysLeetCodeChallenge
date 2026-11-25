class Solution {
public:
    int lengthOfLastWord(string s) {
        int x=s.length()-1;
        int count =0;
        while(x>=0&&s[x]==' '){
            x--;
        }
        while(x>=0&&s[x]!=' '){
            count++;
            x--;
        }
        return count;
    }
};