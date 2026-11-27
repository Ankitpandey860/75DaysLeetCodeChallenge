class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string p="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!p.empty()){
                    st.push(p);
                }
                p.clear();
            }
            else{
                p+=s[i];
            }
        }
        if(!p.empty()){
            st.push(p);
        }
        p.clear();
        while(!st.empty()){
            p+=st.top();
            st.pop();
            if(!st.empty())
            p+=' ';
        }
        return p;
    }
};