class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp=0;
        for(auto it:nums){
            temp=temp^it;
        }
        int i=0;
        while((temp & (1<<i))==0){
            i++;
        }
        vector<int>st,unst;
        for(auto it:nums){
            if((it & (1<<i)) == 0){
                unst.push_back(it);
            }
            else{
                st.push_back(it);
            }
        }
        int num1=0,num2=0;
        for(auto it:st){
            num1=num1^it;
        }
        for(auto it:unst){
            num2=num2^it;
        }
        if(num1<num2){
            return {num1,num2};
        }
        else
         return {num2,num1};
    }
};