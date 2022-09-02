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
vector<ll> fact(2000009);
int prime[1000001];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
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
char ab[51][51];
ll dp[51][51];
ll h, w;
bool isvalid(ll i, ll j, ll x, ll y)
{

    if (i < 0 || i >= h || j < 0 || j >= w || (ab[i][j] != ab[x][y] + 1))
        return false;
    return true;
}
ll dfs(ll x, ll y)
{
    ll ans = 0;
    ll r = dp[x][y];
    if (r != -1)
        return r;

    for (ll i = 0; i < 8; i++)
    {
        if (isvalid(x + dx[i], y + dy[i], x, y))
            ans = max(ans, dfs(x + dx[i], y + dy[i]));
    }
    ans += 1;
    return ans;
}
void solve()
{
    while (true)
    {
        ll t = 1;
        cin >> h >> w;
        if (h == 0 && w == 0)
            return;
        for (ll i = 0; i < h; i++)
        {
            for (ll j = 0; j < w; j++)
                cin >> ab[i][j];
        }
        ll ans = 0;
        for (ll i = 0; i < h; i++)
        {
            for (ll j = 0; i < w; j++)
            {
                if (ab[i][j] == 'A')
                {
                    memset(dp, -1, sizeof(dp));
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        cout << "Case " << t << ": " << ans << '\n';
        t++;
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
