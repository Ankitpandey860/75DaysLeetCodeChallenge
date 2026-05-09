class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        q.push({beginWord,1});
        while(!q.empty()){
            string curr=q.front().first;
            int step=q.front().second;
            if(curr==endWord) return step;
            q.pop();
            for(int i=0;i<curr.length();i++){
                char ch=curr[i];
                for(int j=0;j<26;j++){
                    curr[i]='a'+j;
                    if(st.find(curr)!=st.end()){
                        q.push({curr,step+1});
                        st.erase(curr);
                    }
                }
                curr[i]=ch;
            }
        }
        return 0;
    }
};