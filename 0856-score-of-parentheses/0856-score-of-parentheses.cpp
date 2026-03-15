class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(-1);
            }
            else{
                if(!st.empty()&&st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    if(st.top()==-1){
                        st.pop();
                        st.push(1);
                    }
                    else{
                        int val=0;
                        while(!st.empty()&&st.top()!=-1){
                            val+=st.top();
                            st.pop();
                        }
                        st.pop();
                        st.push(2*val);
                    }
                }
            }
        }
        int ans=0;
        while(!st.empty()&&st.top()!=-1){
            if(st.top()==-1){
                st.pop();
                continue;
            }
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};