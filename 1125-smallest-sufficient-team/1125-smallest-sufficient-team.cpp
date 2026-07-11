class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int np = people.size();
        
        // Map each skill string to a bit index
        unordered_map<string, int> skill_to_bit;
        for (int i = 0; i < n; i++) {
            skill_to_bit[req_skills[i]] = i;
        }
        
        // Convert each person's skills into a bitmask
        vector<int> ppl_masks(np, 0);
        for (int i = 0; i < np; i++) {
            for (const string& skill : people[i]) {
                if (skill_to_bit.count(skill)) {
                    ppl_masks[i] |= (1 << skill_to_bit[skill]);
                }
            }
        }
        
        // dp[mask] will store the smallest team (vector of indices) that achieves 'mask'
        // Target mask is (1 << n) - 1 (all skills covered)
        int target_mask = (1 << n);
        vector<vector<int>> dp(target_mask);
        
        // Base case: to get 0 skills, we need an empty team (dp[0] is already empty)
        // We use a boolean array or check team sizes to know if a mask is reachable.
        vector<bool> reachable(target_mask, false);
        reachable[0] = true;
        
        // Iterate through each person
        for (int i = 0; i < np; i++) {
            int person_mask = ppl_masks[i];
            if (person_mask == 0) continue; // Skip if they have no relevant skills
            
            // Iterate through all current combined skill states backward
            // to avoid using the same person multiple times in one step
            for (int mask = target_mask - 1; mask >= 0; mask--) {
                if (!reachable[mask]) continue;
                
                int next_mask = mask | person_mask;
                
                // If next_mask hasn't been reached yet, OR we found a smaller team for it
                if (!reachable[next_mask] || dp[mask].size() + 1 < dp[next_mask].size()) {
                    dp[next_mask] = dp[mask];       // Copy the previous team
                    dp[next_mask].push_back(i);    // Add the current person
                    reachable[next_mask] = true;
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};