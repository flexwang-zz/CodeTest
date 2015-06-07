class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > G(numCourses);
        for (int i=0; i<prerequisites.size(); i++)
            G[prerequisites[i].first].push_back(prerequisites[i].second);
        vector<int> state(numCourses, 0);
        for (int i=0; i<numCourses; i++)
            if (!dfs(i, G, state)) return false;
        return true;
    }
    
    bool dfs(int v, vector<vector<int> > &G, vector<int> &state) {
        if (state[v] == 1)
            return false;
        if (state[v] == 2)
            return true;
        state[v] = 1;
        for (int i=0; i<G[v].size(); i++)
            if (!dfs(G[v][i], G, state)) return false;
        state[v] = 2;
        return true;
    }
};