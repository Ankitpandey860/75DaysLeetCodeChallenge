class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int op=0;
        int cl=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    cl++;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size()+cl;
    }
};