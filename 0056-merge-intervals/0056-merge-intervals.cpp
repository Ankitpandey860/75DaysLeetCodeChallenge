class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(i==intervals.size()-1){
                ans.push_back({st,end});
            }
            else if(end>=intervals[i+1][0]){
                end=max(intervals[i+1][1],end);
            }
            else{
                ans.push_back({st,end});
                st=intervals[i+1][0];
                end=intervals[i+1][1];
            }
        }
        return ans;
    }
};