class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;

        }
        /*vector<int>temp(1001,0);
        for (auto &p : map) {
            temp[p.second]++;   // p.second = frequency
        }
        

        for(int i=0;i<1001;i++){
            if(temp[i]>1){
                return false;
            }
        }
        return true;*/
        set<int>setp;
        for (auto &p : map) {
            setp.insert(p.second);   // p.second = frequency
        }
        return map.size()==setp.size();
    }
};