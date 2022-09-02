#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define REP(i, n) for (int i = 1; i <= n; i++)
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<ll, ll> pl;
#define cin(a, n)              \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define store(b, n)              \
    for (int i = 1; i <= n; i++) \
        b[i] = a[i];
ll a[1000005], b[1000005];
ll vis[100001], ans[100001];
vector<ll> graph[100001], revg[100001], scc, order;

void dfs(int node)
{
    vis[node] = 1;
    for (int v : graph[node])
    {
        if (vis[v] == false)
            dfs(v);
    }

    order.push_back(node);
}

void dfs1(int node)
{
    scc.push_back(node);
    vis[node] = 1;
    for (int v : revg[node])
    {
        if (vis[v] == false)
            dfs1(v);
    }
}

void updateAnswer()
{
    if (scc.size() <= 1)
        return;

    for (int node : scc)
        ans[node] = 1;
}
void solve()
{
    int n, m, a, b;
    cin >> n >> m;

    REP(i, m)
    cin >> a >> b,
        graph[a].push_back(b), revg[b].push_back(a);

    REP(i, n)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    reverse(order.begin(), order.end());
    REP(i, n)
    vis[i] = 0;

    for (int node : order)
    {
        if (vis[node] == false)
        {
            scc.clear();
            dfs1(node);
            updateAnswer();
        }
    }

    REP(i, n)
    cout << ans[i] << " ";
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
