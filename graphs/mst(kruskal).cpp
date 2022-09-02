#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
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
ll vis[100001], dis[100001], par[100001];
vector<ll> adj[100001];
char s[100001];
struct edge
{
    ll x, y, w;
};
edge ar[100001];
bool comp(edge x, edge y)
{
    if (x.w < y.w)
        return true;
    return false;
}
ll find(ll x)
{
    if (par[x] == -1)
        return x;
    return par[x] = find(par[x]);
}
void merge(ll x, ll y)
{
    par[x] = y;
}

void solve()
{
    ll n, m, x, y, w, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        par[i] = -1;
    for (i = 0; i < m; i++)
    {
        cin >> ar[i].x >> ar[i].y >> ar[i].w;
    }
    ll sum = 0;
    sort(ar, ar + m, comp);
    for (int i = 0; i < m; i++)
    {
        x = find(ar[i].x);
        y = find(ar[i].y);

        if (x != y)
        {
            sum += ar[i].w;
            merge(x, y);
        }
    }
    cout << sum;
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
