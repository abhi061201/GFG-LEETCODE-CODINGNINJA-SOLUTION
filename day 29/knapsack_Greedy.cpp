#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class compare
{   public :
    bool operator()(pii a, pii b)
    {

        double ratioA = a.second / (a.first + 0.0);
        double ratioB = b.second / (b.first + 0.0);
        return ratioA < ratioB;
    }
};
double GreedyKp(int wt[], int profit[], int W, int n)
{

    vector<pii> items;
    for (int i = 0; i < n; i++)
    {

        items.push_back({wt[i], profit[i]});
    }
    priority_queue<pii, vector<pii>, compare> pq;
    for (auto it : items)
    {
        pq.push(it);
    }
    double profit_max = 0.0;
    while (!pq.empty() && W != 0)
    {

        int cur_weight = pq.top().first;
        int cur_profit = pq.top().second;
        pq.pop();
        if (cur_weight <= W)
        {
            profit_max += cur_profit;
            W = W - cur_weight;
        }
        else
        {
            profit_max += (cur_profit / (cur_weight + 0.0)) * W;
            W = 0;
        }
    }
    return profit_max;
}

int main()
{
    cout << "Enter the no. of items\n";
    int n;
    cin >> n;
    cout << "Enter the size of knapsack\n";
    int W = 0;
    cin >> W;
    cout << "enter the weight of item with its profit\n";
    int weight[n];
    int profit[n];

    for (int i = 0; i < n; i++)
    {
        int wt, val;
        cin >> wt >> val;
        weight[i] = wt;
        profit[i] = val;
    }
    cout << "your Maxmimum profit is : " << GreedyKp(weight, profit, W, n);

    return 0;
}