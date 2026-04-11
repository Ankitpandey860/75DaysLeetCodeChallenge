class Solution {
public:
    int priority(char ch){
        if(ch=='*'||ch=='/'){
            return 2;
        }
        else{
            return 1;
        }
    }
    vector<string>conv(string s){
        vector<string>postfix;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                long long val=0;
                while(i<s.length()&&isdigit(s[i])){
                    val=val*10+s[i]-'0';
                    i++;
                }
                i--;
                postfix.push_back(to_string(val));
            }
            else{
                while(!st.empty()&&priority(st.top())>=priority(s[i])){
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
           
        }
        while(!st.empty()){
            postfix.push_back(string(1, st.top()));
            st.pop();
        }
        return postfix;
    }
    int calculate(string s) {
        vector<string> postfix=conv(s);
        stack<int>st;
        for(int i=0;i<postfix.size();i++){
            if(postfix[i]=="+"){
                int second=0;
                if(!st.empty()){
                    second=st.top();
                    st.pop();
                }
                int first=0;
                if(!st.empty()){
                    first=st.top();
                    st.pop();
                }
                st.push(first+second);
            }
            else if(postfix[i]=="*"){
                int second=0;
                if(!st.empty()){
                    second=st.top();
                    st.pop();
                }
                int first=0;
                if(!st.empty()){
                    first=st.top();
                    st.pop();
                }
                st.push(first*second);
            }
            else if(postfix[i]=="-"){
                int second=0;
                if(!st.empty()){
                    second=st.top();
                    st.pop();
                }
                int first=0;
                if(!st.empty()){
                    first=st.top();
                    st.pop();
                }
                st.push(first-second);
            }
            else if(postfix[i]=="/"){
                int second=0;
                if(!st.empty()){
                    second=st.top();
                    st.pop();
                }
                int first=0;
                if(!st.empty()){
                    first=st.top();
                    st.pop();
                }
                st.push(first/second);
            }
            else{
                st.push(stoi(postfix[i]));
            }
        }
        return st.top();
    }
};