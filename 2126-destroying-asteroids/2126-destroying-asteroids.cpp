class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(mass<arr[i]) return false;
            mass+=arr[i];
        }
        return true;
    }
};   