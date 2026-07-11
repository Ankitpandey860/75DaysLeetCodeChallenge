class Solution {
public:

    int divisibleGame(vector<int>& nums) {
        int mod=1e9+7;
        unordered_set<int>st;
        for(auto it:nums){
            
            /*for(int i=2;i*i<=it;i++){
                if(it%i==0){
                    st.insert(i);
                    st.insert(it/i);
                }
            }*/
            for(int i=1;i*i<=it;i++){
                if(it%i==0){
                    st.insert(i);
                    if(i*i!=it)
                        st.insert(it/i);
                }
            }
        }
        if(st.size()==1 && st.count(1))
            st.insert(2);
        int ans=INT_MIN;
        int maxdiff=INT_MIN;
        int bestk=1;
        for(auto it:st){
            if(it==1) continue;
            int sum=0;
            int temp=INT_MIN;
            for(auto num:nums){
                
                if(num%it==0){
                    sum+=num;
                }
                else{
                    sum-=num;
                }
                temp=max(sum,temp);
                if(sum<0) sum=0;
            }
            if(temp>maxdiff||(temp==maxdiff&&it<bestk)){
                ans=((1ll*temp*it)%mod+mod)%mod;
                maxdiff=temp;
                bestk=it;
            }
        }
        return ans;
    }
};
