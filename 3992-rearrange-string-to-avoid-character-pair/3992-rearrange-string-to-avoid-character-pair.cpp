class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        sort(s.begin(),s.end());
        if(x<y){
            reverse(s.begin(),s.end());
            return s;
        }
        return s;
    }
};