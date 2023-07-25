#include <bits/stdc++.h>

long long merge(long long *arr, int s, int mid, int e)
{
    int i = s, j = mid + 1, temp[e - s + 1];
    int res = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] > arr[j])
        {
            res += (mid - i + 1);
            j++;
        }
        else
            i++;
    }
    i = s, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp[cnt++] = arr[i++];
        }
        else
        {
            temp[cnt++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[cnt++] = arr[i++];
    }
    while (j <= e)
    {
        temp[cnt++] = arr[j++];
    }
    cnt = 0;
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[cnt++];
    }
    return res;
}
long long mergesort(long long *arr, int s, int e)
{
    if (s >= e)
        return 0;
    int count = 0;
    int mid = (s) + (e - s) / 2;
    count += mergesort(arr, s, mid);
    count += mergesort(arr, mid + 1, e);
    count += merge(arr, s, mid, e);
    return count;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergesort(arr, 0, n - 1);
}