class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int x=matrix[0].size();
        for(int i=0;i<x;++i){
            for(int j=i+1;j<x;++j){
                swap(matrix[i][j],matrix[j][i]);

            }
        }
        int y=0;
        for(int i=0;i<x;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};