// User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &m)
    {
        int n = m.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == -1)
                    m[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (m[j][i] != INT_MAX && m[i][k] != INT_MAX)
                        m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == INT_MAX)
                    m[i][j] = -1;
            }
        }
    }
};