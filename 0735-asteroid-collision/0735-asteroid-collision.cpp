class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            int temp=asteroids[i];
            if(st.empty()||temp>0){
                st.push(temp);
            }
            else{
                while(!st.empty()&&st.top()<abs(temp)&&st.top()>0){
                    st.pop();
                }
                if(!st.empty()&&st.top()==abs(temp)) st.pop();
                else{
                    if(st.empty()||st.top()<0){
                        st.push(temp);
                    }
                }
            }
        }
        vector<int>ans;
        if(st.empty()) return ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};