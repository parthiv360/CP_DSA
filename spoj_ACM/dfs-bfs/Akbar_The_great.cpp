#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef unsigned long long int llu;
typedef pair<ll, ll> pl;
#define cin(a, n)              \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define store(b, n)              \
    for (int i = 1; i <= n; i++) \
        b[i] = a[i];
lli a[1000005], b[1000005];
ll vis[100001], dis[100001];
vector<ll> adj[100001];
char s[100001];
vector<pair<ll, ll>> vpl;
vector<ll> fact(2000009);
int prime[1000001];
void sieve()
{
    int maxn = 1000000;
    for (int i = 0; i <= maxn; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
                prime[j] = 0;
        }
    }
}
void factorial()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= 2000009; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}
ll modexpo(ll x, ll y)
{
    ll ans = 1;
    x = (x % mod);
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        y >>= 1;
    }
    return ans % mod;
}
ll inv_mod(ll x)
{
    ll a = 1, p = x, n = 1000000005;
    while (n)
    {
        if (n & 1)
            a = (a * p) % mod;
        p = (p * p) % mod;
        n >>= 1;
    }
    return a;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    else
        return gcd(b, a % b);
}
bool bfs()
{
    queue<pair<ll, ll>> q;
    ll l = vpl.size();
    rep(i, l)
    {
        q.push({vpl[i].first, vpl[i].second});
        vis[vpl[i].first] = vpl[i].first;
    }
    while (!q.empty())
    {
        ll u = q.front().first;
        ll str = q.front().second;
        assert(vis[u]);
        q.pop();
        if (str <= 0)
            continue;
        for (ll v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = vis[u];
                q.push({v, str - 1});
            }
            else
            {
                if (vis[v] == vis[u])
                    continue;
                assert(vis[v] != vis[u]);
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    ll n, m, r;
    cin >> n >> r >> m;
    ll x, y;
    rep1(i, n)
    {
        adj[i].clear();
        vis[i] = 0;
    }
    vpl.clear();
    rep(i, r)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, m)
    {
        cin >> x >> y;
        vpl.push_back({x, y});
    }
    bool f = bfs();
    if (!f)
        cout << "No\n";
    else
    {
        bool ans = true;
        rep1(i, n)
        {
            if (!vis[i])
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
