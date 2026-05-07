class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>>pq;
        for(int i=0;i<k;i++){
            long long dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        for(int i=k;i<points.size();i++){
            long long dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
            pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            ans.push_back({r,c});
        }
        return ans;
    }
};


