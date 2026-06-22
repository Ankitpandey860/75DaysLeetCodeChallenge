class cmp{
    public:
    bool operator()(int &a, int& b){
        return a>b;
    }
};
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>temp;
        for(int i=0;i<nums1.size();i++){
            temp.push_back({nums2[i],nums1[i]});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        long long sum=0;
        priority_queue<int,vector<int>,cmp>pq;
        for(int i=0;i<k;i++){
            sum+=temp[i].second;
            pq.push(temp[i].second);
        }
        long long ans=sum*temp[k-1].first;
        for(int i=k;i<temp.size();i++){
            sum+=temp[i].second;
            pq.push(temp[i].second);
            int curr=pq.top();
            pq.pop();
            sum-=curr;
            long long possans=sum*temp[i].first;
            ans=max(ans,possans);
        }
        return ans;
    }
};