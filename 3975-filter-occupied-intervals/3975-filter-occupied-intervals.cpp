class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intrvl, int freeStart, int freeEnd) {
        sort(intrvl.begin(),intrvl.end());
        int prst=intrvl[0][0];
        int prend=intrvl[0][1];
        int n=intrvl.size();
        vector<vector<int>> merged;
        for(int i=1;i<intrvl.size();i++){
            if(intrvl[i][0]<=prend+1){
                prend=max(prend,intrvl[i][1]);
            }
            else{
                // merged interval = [prst, prend]
                // free interval   = [freeStart, freeEnd]

                if(prend < freeStart || prst > freeEnd){
                    // No overlap
                    merged.push_back({prst,prend});
                }
                else if(prst >= freeStart && prend <= freeEnd){
                    // Completely inside free interval
                    // discard
                }
                else if(prst < freeStart && prend <= freeEnd){
                    // Left part survives
                    merged.push_back({prst,freeStart-1});
                }
                else if(prst >= freeStart && prend > freeEnd){
                    // Right part survives
                    merged.push_back({freeEnd+1,prend});
                }
                else{
                    // Free interval lies completely inside merged interval
                    // Split into two intervals

                    merged.push_back({prst,freeStart-1});
                    merged.push_back({freeEnd+1,prend});
                }
                prst=intrvl[i][0];
                prend=intrvl[i][1];
            }
        }
            if(prend < freeStart || prst > freeEnd){
                // No overlap
                merged.push_back({prst,prend});
            }
            else if(prst >= freeStart && prend <= freeEnd){
                // Completely inside free interval
                // discard
            }
            else if(prst < freeStart && prend <= freeEnd){
                // Left part survives
                merged.push_back({prst,freeStart-1});
            }
            else if(prst >= freeStart && prend > freeEnd){
                // Right part survives
                merged.push_back({freeEnd+1,prend});
            }
            else{
                // Free interval lies completely inside merged interval
                // Split into two intervals

                merged.push_back({prst,freeStart-1});
                merged.push_back({freeEnd+1,prend});
            }
        
    
        return merged;
    }
};