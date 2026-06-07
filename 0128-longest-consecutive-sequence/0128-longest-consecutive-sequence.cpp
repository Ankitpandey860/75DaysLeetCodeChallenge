class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxlen=1;
        for(auto it: st){
            if(st.contains(it-1)){
                continue;
            }else{
                int len=1;
                int temp=it;
                while(st.contains(++temp)){
                    len++;
                    maxlen=max(len,maxlen);
                }
            }
        }
        return maxlen;
    }
};