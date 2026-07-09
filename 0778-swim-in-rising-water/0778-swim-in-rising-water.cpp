class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // Alias for readability
        using CustomPair = std::pair<int, std::pair<int, int>>;

        // Syntax: priority_queue<Type, Container, Comparison>
        std::priority_queue<CustomPair, std::vector<CustomPair>, std::greater<CustomPair>> pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        int ans=grid[0][0];
        int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;

            int curr=pq.top().first;
            pq.pop();
            ans=max(ans,curr);
            if(r==n-1&&c==m-1){
                return ans;
            }
            for(auto it:arr){
                int nr=r+it[0];
                int nc=c+it[1];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]){
                    pq.push({grid[nr][nc],{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return ans;
    }
};