int timestamp=0;
class Twitter {
public:
    Twitter() {
        
    }

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweets;
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        priority_queue<pair<int,pair<int,pair<int,int>>>>pq;
        //time-tweetid-userid-index
        for(auto &fllws:followMap[userId]){
            if(tweets[fllws].empty()) continue;
            int idx=tweets[fllws].size()-1;
            int tmstmp=tweets[fllws][idx].first;
            int twtid=tweets[fllws][idx].second;
            pq.push({tmstmp,{twtid,{fllws,idx}}});
        }
        int i=10;
        vector<int>ans;
        while(pq.size()&&i--){
            int idx=pq.top().second.second.second;
            int tmstmp=pq.top().first;
            int twtid=pq.top().second.first;
            int usrid=pq.top().second.second.first;
            pq.pop();
            ans.push_back(twtid);
            if(idx>0){
                int tmstmp2=tweets[usrid][idx-1].first;
                int twtid2=tweets[usrid][idx-1].second;
                pq.push({tmstmp2,{twtid2,{usrid,idx-1}}});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */