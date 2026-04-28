#define ll long long

class SegmentTree {
public:
    int n;
    vector<ll> segTree;

    SegmentTree (ll _n) {
        n = _n;
        segTree.resize(4 * n, LLONG_MIN);
    }

    void updateSegTree (ll i, ll idx, ll l, ll r, ll val) {
        if (l == r) {
            segTree[i] = val;
            return;
        }

        ll mid = (l + r) / 2;
        if (idx <= mid) {
            updateSegTree(2 * i + 1, idx, l, mid, val);
        } else {
            updateSegTree(2 * i + 2, idx, mid + 1, r, val);
        }

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    ll Query (ll i, ll start, ll end, ll l, ll r) {
        if (r < start || l > end) {
            return LLONG_MIN;
        }

        if (l >= start && r <= end) {
            return segTree[i];
        }

        ll mid = (l + r) / 2;
        return max(Query(2 * i + 1, start, end, l, mid), 
                    Query(2 * i + 2, start, end, mid + 1, r));
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        unordered_map<int, int> position;
        for (int i = 0; i < vals.size(); i++) {
            position[vals[i]] = i;
        }

        SegmentTree segInc(n), segDec(n);
        
        vector<vector<ll>> dp(n, vector<ll> (2, 0));
        // dp[i][0] = maximum sum of elements in the sequence such that
        //              ith element is increasing (... < nums[i])

        // dp[i][1] = maximum sum of elements in the sequence such that
        //              ith element is decreasing (... > nums[i])

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                int pos = position[nums[i - k]];
                segInc.updateSegTree(0, pos, 0, n - 1, dp[i - k][0]);
                segDec.updateSegTree(0, pos, 0, n - 1, dp[i - k][1]);
            }

            int p = position[nums[i]];

            ll bestDec = segDec.Query(0, 0, p - 1, 0, n - 1);
            ll bestInc = segInc.Query(0, p + 1, n - 1, 0, n - 1);

            dp[i][0] = nums[i];
            if (bestDec != LLONG_MIN) {
                dp[i][0] = max(dp[i][0], nums[i] + bestDec);
            }

            dp[i][1] = nums[i];
            if (bestInc != LLONG_MIN) {
                dp[i][1] = max(dp[i][1], nums[i] + bestInc);
            }

            // cout << dp[i][0] << " " << dp[i][1] << endl << endl;

            ans = max({ans, dp[i][0], dp[i][1]});
        }

        return ans;
    }
};