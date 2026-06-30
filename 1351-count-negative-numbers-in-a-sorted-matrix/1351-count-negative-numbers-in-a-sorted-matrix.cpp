class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0;
        int count = 0;
        int j=grid[0].size()-1;
        while(i<grid.size() && j>=0){
            if(grid[i][j]<0){
                int n = grid.size();
                j--;
                count = count+n-i;

            }
            else{
                i++;

            }
        }
        return count;
    }
};