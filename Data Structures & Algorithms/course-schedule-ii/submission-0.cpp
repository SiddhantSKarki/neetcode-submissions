class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // build in_degree and adj list
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (vector<int>& num: prerequisites) {
            in_degree[num[0]]++;
            adj[num[1]].push_back(num[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            // process its neighbors
            for (int nei: adj[node]) {
                in_degree[nei]--;
                if (in_degree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return order.size() == numCourses? order : vector<int>({});
    }
};
