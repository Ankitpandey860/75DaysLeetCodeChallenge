class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int sum=0;
        int sign=1;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                long long val=0;
                while(i<s.length()&&isdigit(s[i])){
                    val=val*10+s[i]-'0';
                    i++;
                }
                i--;
                sum=sum+val*sign;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=1;
            }
            else if(s[i]==')'){
                int prevsign=st.top();
                st.pop();
                int prevsum=st.top();
                st.pop();
                sum=prevsum+sum*prevsign;
            }
        }
        return sum;
    }
};