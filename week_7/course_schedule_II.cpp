class Solution {
public:

    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int numCourses, vector<int>&indegree)
    {
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                result.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int &v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    result.push_back(v);
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses)
        {
            return {};
        }
       
        return result;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int>indegree(numCourses, 0);

        for (auto &pre: prerequisites)
        {
            int a = pre[0];
            int b = pre[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};