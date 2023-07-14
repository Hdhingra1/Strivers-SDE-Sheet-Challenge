int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int, int>> v;
    for (int i = 0; i < end.size(); i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int e = -1;
    for (auto it : v)
    {
        if (e < it.second)
        {
            ans++;
            e = it.first;
        }
    }
    return ans;
}