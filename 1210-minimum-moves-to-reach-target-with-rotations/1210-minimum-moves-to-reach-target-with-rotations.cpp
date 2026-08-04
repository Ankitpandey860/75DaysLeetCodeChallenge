using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // visited[r][c][dir]: r, c is Tail position. dir: 0 = Horizontal, 1 = Vertical
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
        
        // Queue stores: {tail_row, tail_col, dir, steps}
        queue<tuple<int, int, int, int>> q;
        
        // Start: Tail at (0,0), Horizontal (0), 0 steps
        q.push({0, 0, 0, 0});
        visited[0][0][0] = true;

        while (!q.empty()) {
            auto [r, c, dir, step] = q.front();
            q.pop();

            // Target state: Tail at (n-1, n-2) and Horizontal (0)
            if (r == n - 1 && c == n - 2 && dir == 0) {
                return step;
            }

            if (dir == 0) { // HORIZONTAL (Tail: r, c | Head: r, c+1)
                // 1. Move Right
                if (c + 2 < n && grid[r][c + 2] == 0) {
                    if (!visited[r][c + 1][0]) {
                        visited[r][c + 1][0] = true;
                        q.push({r, c + 1, 0, step + 1});
                    }
                }
                // 2. Move Down
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                    if (!visited[r + 1][c][0]) {
                        visited[r + 1][c][0] = true;
                        q.push({r + 1, c, 0, step + 1});
                    }
                }
                // 3. Rotate Clockwise
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                    if (!visited[r][c][1]) {
                        visited[r][c][1] = true;
                        q.push({r, c, 1, step + 1});
                    }
                }
            } else { // VERTICAL (Tail: r, c | Head: r+1, c)
                // 1. Move Right
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0) {
                    if (!visited[r][c + 1][1]) {
                        visited[r][c + 1][1] = true;
                        q.push({r, c + 1, 1, step + 1});
                    }
                }
                // 2. Move Down
                if (r + 2 < n && grid[r + 2][c] == 0) {
                    if (!visited[r + 1][c][1]) {
                        visited[r + 1][c][1] = true;
                        q.push({r + 1, c, 1, step + 1});
                    }
                }
                // 3. Rotate Counter-Clockwise
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0) {
                    if (!visited[r][c][0]) {
                        visited[r][c][0] = true;
                        q.push({r, c, 0, step + 1});
                    }
                }
            }
        }

        return -1;
    }
};