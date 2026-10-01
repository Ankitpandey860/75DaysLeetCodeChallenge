class Solution {
public:
    int score(vector<string>& cards, char x) {
        int both=0;
        int f=0;
        int sec=0;
        vector<int>cnt1(10,0),cnt2(10,0);
        for(auto &it:cards){
            if(it[0]==x&&it[1]==x) both++;
            else if(it[0]==x) {
                f++;
                int idx=it[1]-'a';
                cnt1[idx]++;
            }
            else if(it[1]==x) {
                int idx=it[0]-'a';
                cnt2[idx]++;
                sec++;
            }
        }
        int max1=0,max2=0;
        for(int i=0;i<10;i++){
            max1=max(max1,cnt1[i]);
            max2=max(max2,cnt2[i]);
        }
        int fpair=min(f/2,f-max1);
        int fleft=f-fpair*2;
        int spair=min(sec/2,sec-max2);
        int sleft=sec-spair*2;
        int ans=fpair+spair+min(both,fleft+sleft);
        if(fleft+sleft<both){
            ans=ans+min(fpair+spair,(both-fleft-sleft)/2);
        }
        return ans;
    }
};