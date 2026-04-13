class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<char,int>> blocks;
        vector<int>freq(26,0);
        int cnt=1;
        char ch=text[0];
        freq[text[0]-'a']++;
        for(int i=1;i<text.length();i++){
            if(text[i]==ch){
                cnt++;
            }
            else{
                blocks.push_back({ch,cnt});
                cnt=1;
                ch=text[i];
            }
            freq[text[i]-'a']++;
        }
        blocks.push_back({ch,cnt});
        int ans=0;
        for(int i=0;i<blocks.size();i++){
            int len=blocks[i].second;
            ch=blocks[i].first;
            ans=max(ans,min(freq[ch-'a'],len+1));
            if(i+2<blocks.size()){
                if(blocks[i].first==blocks[i+2].first&&blocks[i+1].second==1){
                    ans=max(ans,min(freq[ch-'a'],blocks[i].second+blocks[i+2].second+1));
                }
            }
        }
        return ans;
    }
};