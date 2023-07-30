#include <bits/stdc++.h> 
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[2] > job2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);
    int maxProfit = 0;
    int numberOfJobs = 0;
    int maxDeadline = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
    set<int, greater<int>> slots;
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }
    vector<int> ans;
    for (int i = 0; i < jobs.size(); i++)
    {

        if (slots.size() == 0 || jobs[i][1] < *slots.rbegin())
        {
            continue;
        }
        int availableSlot = *slots.lower_bound(jobs[i][1]);
        maxProfit = maxProfit + jobs[i][2];
        numberOfJobs += 1;
        slots.erase(availableSlot);
    }
    ans.push_back(numberOfJobs);
    ans.push_back(maxProfit);
    return ans;
}