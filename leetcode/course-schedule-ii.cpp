class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (int i=0; i<prerequisites.size(); i++) {
            int s = prerequisites[i].second;
            int t = prerequisites[i].first;
            G[s].push_back(t);
            indegree[t]++;
        }
        
        queue<int> q;
        for (int i=0; i<indegree.size(); i++)
            if (!indegree[i]) q.push(i);
            
        vector<int> ans;
        while (!q.empty()) {
            int v = q.front();
            ans.push_back(v);
            q.pop();
            for (int i=0; i<G[v].size(); i++) {
                indegree[G[v][i]] --;
                if (!indegree[G[v][i]]) q.push(G[v][i]);
            }
        }
        if (ans.size() != numCourses) return vector<int>();
        return ans;
    }
};