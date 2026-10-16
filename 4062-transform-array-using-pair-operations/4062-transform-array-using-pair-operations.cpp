class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum=0;
        for(int i=0;i<source.size();i++){
            sum+=source[i];
            sum-=target[i];
        }
        return sum==0;
    }
};