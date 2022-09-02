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
ll find(ll a)
{
    if (par[a] < 0)
        return a;
    return par[a] = find(par[a]);
}
void Union(ll a, ll b)
{
    par[a] += par[b];
    par[b] = a;
}

void solve()
{
    ll n, m, i, j;
    cin >> n >> m;
    rep1(i, n)
        par[i] = -1;
    ll x, y;
    while (m--)
    {
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if (x != y)
            Union(x, y);
    }
    lli res = 1;

    rep1(i, n)
    {
        if (par[i] < 0)
            res = (res * abs(par[i])) % mod;
    }
    cout << res;
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
