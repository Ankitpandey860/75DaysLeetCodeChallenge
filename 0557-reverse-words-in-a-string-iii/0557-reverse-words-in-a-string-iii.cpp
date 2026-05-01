class Solution {
public:
    void reverse(int i,int j ,string &s){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(j<s.length()){
            while(j<s.length()&&s[j]!=' '){
                j++;
            }
            reverse(i,j-1,s);
            j++;
            i=j;
        }
        return s;
    }
};