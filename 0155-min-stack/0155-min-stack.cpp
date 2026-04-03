class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else if(val>mini){
            st.push(val);
        }
        else{
            long long encoded=2ll*val-mini;
            st.push(encoded);
            mini=val;
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        else if(st.top()>mini){
            st.pop();
            return;
        } 
        else{
            int val=st.top();
            mini=2*mini-val;
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>mini){
            return st.top();
        }
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */