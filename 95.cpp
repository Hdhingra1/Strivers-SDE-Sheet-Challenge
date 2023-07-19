class Solution
{
public:
    int orangesRotting(vector<vector<int>> &g)
    {
        queue<pair<int, int>> q;
        int f = 0;
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                if (g[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (g[i][j] == 1)
                {
                    f++;
                }
            }
        }
        if (f == 0)
            return 0;

        int t = 0;
        while (!q.empty())
        {
            int m = q.size();
            while (m--)
            {
                auto it = q.front();
                q.pop();
                vector<int> r = {-1, 0, 0, 1};
                vector<int> c = {0, -1, 1, 0};
                for (int i = 0; i < 4; i++)
                {
                    int nr = it.first + r[i];
                    int nc = it.second + c[i];
                    if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g.size() && g[nr][nc] == 1)
                    {
                        f--;
                        g[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            t++;
        }
        if (f == 0)
            return t - 1;
        return -1;
    }
};