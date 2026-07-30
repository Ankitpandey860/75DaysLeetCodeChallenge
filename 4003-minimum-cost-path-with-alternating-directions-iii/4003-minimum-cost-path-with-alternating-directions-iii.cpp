class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        using p = tuple<long long, int, int, int>;

        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, 1e18)));
        priority_queue<p, vector<p>, greater<p>> pq;

        // Entry cost at (0, 0) is (0+1)*(0+1) = 1. First action will be Action 1 (odd -> parity = 1).
        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        // Direction indices: 0: Right, 1: Down, 2: Left, 3: Up
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto [cst, i, j, parity] = pq.top();
            pq.pop();

            if (cst > dist[i][j][parity]) continue;
            if (i == m - 1 && j == n - 1) return cst;

            int next_parity = 1 - parity;

            // Option 1: Wait in place
            long long wait_cost = cst + penalty[i][j];
            if (wait_cost < dist[i][j][next_parity]) {
                dist[i][j][next_parity] = wait_cost;
                pq.push({wait_cost, i, j, next_parity});
            }

            // Option 2: Move to adjacent cells
            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + di[dir];
                int nj = j + dj[dir];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    long long enter_cost = 1LL * (ni + 1) * (nj + 1);

                    // Check parity condition
                    // Odd parity (1): Right(0) & Down(1) follow rule
                    // Even parity (0): Left(2) & Up(3) follow rule
                    bool follows_rule = (parity == 1 && (dir == 0 || dir == 1)) || 
                                        (parity == 0 && (dir == 2 || dir == 3));

                    long long move_cost = cst + enter_cost + (follows_rule ? 0 : penalty[i][j]);

                    if (move_cost < dist[ni][nj][next_parity]) {
                        dist[ni][nj][next_parity] = move_cost;
                        pq.push({move_cost, ni, nj, next_parity});
                    }
                }
            }
        }

        return -1;
    }
};