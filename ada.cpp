////////////////////////  Activity Selection ///////////////////////////
/*
#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int start,finish;
};

bool comp(activity a,activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n = 6;
    activity activities[n];

    activities[0].start = 1;
    activities[0].finish = 4;
    activities[1].start = 1;
    activities[1].finish = 2;
    activities[2].start = 3;
    activities[2].finish = 6;
    activities[3].start = 2;
    activities[3].finish = 3;
    activities[4].start = 3;
    activities[4].finish = 5;
    activities[5].start = 5;
    activities[5].finish = 6;

    sort(activities, activities+n, comp);
    cout << "{" << activities[0].start
         << "," << activities[0].finish << "}" << endl;

    int currentFinish = activities[0].finish;

    for(int i = 1; i < n; i++)
    {
        if(currentFinish <= activities[i].start)
        {
            cout << "{" << activities[i].start
                 << "," << activities[i].finish << "}" << endl;
            currentFinish = activities[i].finish;
        }
    }
}
*/




//////////////////////            BFS              ///////////////////
/*

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node+1];

    vector<int> adj[node+1];  //array of vector

    cout << "Enter the edges: " << endl;
    for(int i=0; i<edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for(int i=0; i<=node; i++){
        visit[i]=false;
    }

    queue<int>q;
    q.push(start_node);
    visit[start_node] = true;

    cout << "BFS result: " << endl;
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        cout << fr << endl;
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit[adj[fr][i]])
            {
                visit[adj[fr][i]]=true;
                q.push(adj[fr][i]);
            }
        }
    }
}

*/




/////////////////////         DFS         ////////////////////
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, start_node;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;

    bool visit[node+1];
    vector<int> adj[node+1];  // adjacency list

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // undirected
    }

    cout << "Enter the starting node: ";
    cin >> start_node;

    for(int i = 0; i <= node; i++) {
        visit[i] = false;
    }

    cout << "DFS result: " << endl;

    // DFS using manual stack (no recursion)
    stack<int> st;
    st.push(start_node);
    visit[start_node] = true;

    while(!st.empty()) {
        int fr = st.top();
        st.pop();
        cout << fr << endl;

        // Push unvisited neighbors (can reverse to control order)
        for(int i = adj[fr].size() - 1; i >= 0; i--) {
            int neighbor = adj[fr][i];
            if(!visit[neighbor]) {
                visit[neighbor] = true;
                st.push(neighbor);
            }
        }
    }

    return 0;
}
*/

//////////////////        0/1 knapsack        //////////////////
/*
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int knap (int weight[], int value[], int n, int capacity)
//{
//    int dp[n+1][capacity+1];
//    for (int i=0; i<=n; i++)
//    {
//        for (int w=0; w<=capacity; w++)
//        {
//            if(i == 0 || w == 0)
//            {
//                dp[i][w] = 0;
//            }
//            else
//            {
//                if (w < weight[i-1])
//                {
//                    dp[i][w] = dp[i-1][w];
//                }
//                else
//                {
//                    dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],
//                                   dp[i-1][w]);
//                }
//            }
//        }
//    }
//    return dp[n][capacity];
//}
//
//int main()
//{
//    int weight[] = {2, 3, 4, 5};
//    int value[] = {1, 2, 5, 6};
//    int n = 4, capacity = 8;
//    cout << knap(weight, value, n, capacity);
//}
#include <bits/stdc++.h>
using namespace std;

int knap (int weight[], int value[], int n, int capacity)
{
    int dp[n+1][capacity+1];
    for (int i=0; i<=n; i++)
    {
        for (int w=0; w<=capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else
            {
                if (w < weight[i-1])
                {
                    dp[i][w] = dp[i-1][w];
                }
                else
                {
                    dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],
                                   dp[i-1][w]);
                }
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n,capacity;
    cin >> n >> capacity;
    int weight[n], value[n];

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    cout << knap(weight, value, n, capacity);
}
*/

////////////////////      Dijkstra       ////////////////////
/*
#include<iostream>
#include<vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 100000
void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void shortestPath(vector<pair<int, int> > adj[], int V, int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > >pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto x:adj[u])
        {
            int v=x.first;
            int weight=x.second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    printf("Vertex Distance from Source\n");
    for(int i=0;i<V;++i)
        printf("%d \t\t %d\n",i,dist[i]);

}
int main()
{
    int V=4;
    vector<pair<int,int>>adj[V];
    addEdge(adj,0,1,4);
    addEdge(adj,0,2,2);
    addEdge(adj,0,3,5);
    addEdge(adj,2,3,1);
    shortestPath(adj,V,0);
    return 0;
}
*/




////////////////////      LCS       ////////////////////
/*
#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    cout << lcs(s1, s2) << endl;
}
*/

/////////////////////        Fractional      //////////////////////
/*
#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    cout << lcs(s1, s2) << endl;
}
*/


/////////////////////        Coin Change      //////////////////////

/*
#include <iostream>
#include <algorithm> // For min function

using namespace std;

// Coin Change - Number of Ways
int coinChangeNumWays(int coins[], int n, int amount)
{
    int dp[n+1][amount+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}

// Coin Change - Minimum Number of Coins
int coinChangeMinCoins(int coins[], int n, int amount)
{
    int INF = 1e9;
    int dp[n+1][amount+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = INF;
            if (j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
            }
        }
    }
    return dp[n][amount] == INF ? -1 : dp[n][amount];
}

int main()
{
    int coins[] = {3, 8, 9};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    cout << "Coin Change - Number of Ways: " << coinChangeNumWays(coins, n, amount) << endl;
    cout << "Coin Change - Minimum Number of Coins: " << coinChangeMinCoins(coins, n, amount) << endl;

    return 0;
}
*/


#include <iostream>
#include <algorithm>

const int mx = 1e3+123;
int coins[mx];
using namespace std;

// Coin Change - Number of Ways
int coinChangeNumWays(int coins[], int n, int amount)
{
    int dp[n+1][amount+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}
// Coin Change - Minimum Number of Coins
int coinChangeMinCoins(int coins[], int n, int amount)
{
    int INF = 1e9;
    int dp[n+1][amount+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0) dp[i][j] = INF;
            if (j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1])
            {
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
            }
        }
    }
    return dp[n][amount] == INF ? -1 : dp[n][amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    for( int i = 0; i < n; i++ )
    {
        cin >> coins[i];
    }

    cout << "Coin Change - Number of Ways: " << coinChangeNumWays(coins, n, amount) << endl;
    cout << "Coin Change - Minimum Number of Coins: " << coinChangeMinCoins(coins, n, amount) << endl;

    return 0;
}

