// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(V, 1e8);
        dis[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto j : edges)
            {
                // if(dis[j[0]]!=INT_MAX)
                if (dis[j[1]] > dis[j[0]] + j[2])
                {
                    dis[j[1]] = dis[j[0]] + j[2];
                }
            }
        }
        for (auto j : edges)
        {
            // if(dis[j[0]]!=INT_MAX)
            if (dis[j[1]] > dis[j[0]] + j[2])
            {
                return {-1};
            }
        }
        return dis;
    }
};