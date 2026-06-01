class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp;
            for (int j = 0; j < i + 1; j++) {
                if (i< 1) {
                    temp.push_back(1);
                } else {
                    int temp1 = 0;
                    if(j==i){
                        temp1=1;
                    }
                    else{
                        temp1 += ans[i - 1][j];
                    } 
                    if (j - 1 >=0&&i>1&&i!=j) {
                        temp1 += ans[i - 1][j - 1];
                    }
                    temp.push_back(temp1);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};