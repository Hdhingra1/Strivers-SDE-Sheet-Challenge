class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    bool static cmp(Item a, Item b)
    {
        double w = (double)(a.value) / (double)(a.weight);
        double w1 = (double)(b.value) / (double)(b.weight);
        return w > w1;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double ans = 0, g = 0;
        for (int i = 0; i < n; i++)
        {
            if (g + arr[i].weight <= (double)W)
            {
                ans += arr[i].value;
                g += arr[i].weight;
            }
            else
            {
                ans += (double)(arr[i].value) / (double)(arr[i].weight) * (W - g);
                break;
            }
        }
        return ans;
    }
};