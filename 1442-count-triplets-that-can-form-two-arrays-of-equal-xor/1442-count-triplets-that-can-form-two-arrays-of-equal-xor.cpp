class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int xor1=arr[i];
            for(int k=i+1;k<arr.size();k++){
                xor1=xor1^arr[k];
                if(xor1==0){
                    ans+=(k-i);
                }
            }
        }
        return ans;
    }
};