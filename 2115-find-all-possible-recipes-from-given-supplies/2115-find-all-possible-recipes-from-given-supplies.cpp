class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,list<string>>mp;
        int n=recipes.size();
        unordered_map<string,int>indeg;
        for(int i=0;i<n;i++){
            for(auto& it:ingredients[i]){
                mp[it].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }
        vector<string>ans;
        for(int i=0;i<supplies.size();i++){
            string it=supplies[i];
            for(auto &item:mp[it]){
                indeg[item]--;
                if(indeg[item]==0){
                    supplies.push_back(item);
                    ans.push_back(item);
                }
            }
        }
        
        return ans;
    }
};