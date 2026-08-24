class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        vector<int>left(n,-1),right(n,-1);
        int i=0,j=0;
        while(i<n&&j<station.size()){
            if(skill[i]==station[j]){
                left[i]=j;
                i++;
            }
            j++;
        }
        i=n-1;
        j=station.size()-1;
        while(i>=0&&j>=0){
            if(skill[i]==station[j]){
                right[i]=j;
                i--;
            }
            j--;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,right[i]-left[i-1]);
        }
        return ans;
    }
};