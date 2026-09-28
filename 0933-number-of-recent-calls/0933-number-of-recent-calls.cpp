class RecentCounter {
public:
    int floor(vector<int>&cnt,int val){
        int lo=0;
        int hi=cnt.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(cnt[mid]<val){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
    vector<int>cnt;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        cnt.push_back(t);
        int l=floor(cnt,t-3000);
        return cnt.size()-l;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */