class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            long long t1 = nums[i];

            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> seen;
                long long t2 = nums[j];

                for (int k = j + 1; k < n; k++) {
                    long long need = (long long)target - t1 - t2 - nums[k];

                    if (seen.count(need)) {
                        vector<int> quad = {
                            (int)t1,
                            (int)t2,
                            nums[k],
                            (int)need
                        };

                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};