class Solution {
public:
    int BFS(int src, vector<int> adjList[], vector<bool>& visited) {
        int count = 1;

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adjList[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    count++;
                }
            }
        }

        return count;
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {

        vector<bool> visited(n, false);

        vector<int> adj[n];

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (auto node : restricted) {
            visited[node] = true;
        }

        return BFS(0, adj, visited);
    }
};