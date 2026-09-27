class Solution {
public:
    void reverse(string& s){
        int x=0;
        int y=s.length()-1;
        while(x<y){
            swap(s[x],s[y]);
            x++;
            y--;
        }
    }
    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                string ans="";
                while(!st.empty()&&st.top()!="("){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(ans);
                st.push(ans);
            }
            else{
                string t(1, s[i]);
                st.push(t);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans);
        return ans;
    }
};