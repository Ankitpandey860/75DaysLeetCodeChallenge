class Solution {
public:
    int maskWord(string word) {
        int mask = 0;
        for (auto c : word) mask |= (1 << (c-'a'));
        return mask;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int>mp;
         for (auto word : words) mp[(maskWord(word))]++;

        vector<int>ans;
        for(auto p:puzzles){
            int mask=maskWord(p),submask=mask,first=(1<<p[0]-'a'),curr=0;
            while(submask){
                if(submask&first) curr+=mp[submask];
                submask=(submask-1)&mask;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};