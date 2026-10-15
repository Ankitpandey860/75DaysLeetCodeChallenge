class Solution {
public:
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto const &it : graph[node]) {
                if (visited[it] == -1) {
                    q.push(it);
                    visited[it] = 1 - visited[node];
                }
                if (visited[node] == visited[it]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, -1);
        
        for (int i = 0; i < V; i++) {
            if (visited[i] == -1) {
                if (!bfs(i, graph, visited)) {
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        return true;
    }
};