#include <bits\stdc++.h>
using namespace std;

void Toposort_stack(int i, vector<pair<int, int>> adj[], stack<int> &st, vector<int>& vis)
{
    vis[i] = 1;
    // cout<<i<<" , ";
    for (auto it : adj[i])
    {
        if (!vis[it.first])
        {
            Toposort_stack(it.first, adj, st, vis);
        }
    }
    st.push(i);
}
int main()
{
    cout << "Enter the no. of vertices and edges in your graph\n";
    int n, e;
    cin >> n >> e;
    cout << "Enter the edges with their respective weights\n";
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cout << " Enter the source\n";
    int src;
    cin >> src;
    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
        if (!vis[i])
            Toposort_stack(i, adj, st, vis);

    // while(!st.empty())
    // {
    //     cout << st.top() << " , ";
    //     st.pop();
    // }
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    int i=0;
   while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        if (dist[temp] != INT_MAX)
        {
            for (auto it : adj[temp])

            {
                if (dist[it.first] > it.second + dist[temp])
                {
                    dist[it.first] = it.second + dist[temp];
                }
            }
        }
        i++;
    }

    cout << "Shortest Distance of each node from the source " << src << " is :\n";
    for (int i = 0; i < n+1; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}