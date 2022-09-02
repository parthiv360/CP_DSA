#include <bits/stdc++.h>
using namespace std;
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#define fast                          \
    {                                 \
        ios ::sync_with_stdio(false); \
        cin.tie(0);                   \
        cout.tie(0);                  \
    }
#define pb push_back
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define f(i, a, b) for (ll i = a; i < b; i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define nl cout << "\n";
#define mp make_pair
#define ff first
#define ss second

vector<vector<int>> adj;
vector<int> dp, child, in;

void dfs(int root, int par)
{

    dp[root] = 0;
    child[root] = 1;
    for (auto x : adj[root])
    {
        if (x == par)
            continue;
        dfs(x, root);
        child[root] += child[x];
    }

    vector<int> mine;
    for (auto x : adj[root])
    {
        if (x == par)
            continue;
        mine.pb(x);
    }
    if (mine.size() >= 2)
        dp[root] = max(child[mine[0]] - 1 + dp[mine[1]], child[mine[1]] - 1 + dp[mine[0]]);

    else if (mine.size() == 1)
        dp[root] = child[mine[0]] - 1;
}

int main()
{
    fast
        // srand(time(NULL));

        ll ntc = 1;
    cin >> ntc;

    f(asdfghjk, 1, ntc + 1)
    {
        ll n;
        cin >> n;
        adj = vector<vector<int>>(n + 1);
        dp = vector<int>(n + 1);
        child = vector<int>(n + 1);
        in = vector<int>(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int a;
            int b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            in[a]++;
            in[b]++;
        }

        dfs(1, -1);
        cout << dp[1] << endl;
    }

    return 0;
}