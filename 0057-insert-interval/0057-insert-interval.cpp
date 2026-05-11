class Solution {
public:
    class cmp{
        public:
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.first>b.first;
        }
    };
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        vector<vector<int>>ans;
        for(auto intvrls:intervals){
            pq.push({intvrls[0],intvrls[1]});
        }
        pq.push({newInterval[0],newInterval[1]});
        while(!pq.empty()){
            int st=pq.top().first;
            int end=pq.top().second;
            pq.pop();
            if(!pq.empty()&&end>=pq.top().first){
                int end2=max(end,pq.top().second);
                pq.pop();
                pq.push({st,end2});
            }
            else{
                ans.push_back({st,end});
            }
        }
        return ans;
    }
};