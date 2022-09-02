#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<ll, ll> pl;
#define INF 1000000000
#define cin(a, n)              \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define store(b, n)              \
    for (int i = 1; i <= n; i++) \
        b[i] = a[i];
ll a[1000005], b[1000005];
ll vis[100001], dis[100001];
vector<pair<ll, ll>> adj[100001];
char s[100001];

void solve()
{
    ll n, m, x, y, w, i, j;
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, INF);
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        ll cur = pq.top().second;
        ll curd = pq.top().first;
        pq.pop();

        for (pair<ll, ll> edge : adj[cur])
        {
            if (curd + edge.second < dis[edge.first])
            {
                dis[edge.first] = curd + edge.second;
                pq.push({dis[edge.first], edge.first});
            }
        }
    }

    rep1(i, n)
    {
        cout << dis[i] << " ";
    }
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
