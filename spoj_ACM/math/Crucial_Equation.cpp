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
ll vis[100001], dis[100001];
vector<ll> adj[100001];
char s[100001];
vector<ll> fact(2000009);
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
    return (a % b == 0) ? abs(b) : gcd(b, a % b);
}
void solve()
{
    int t;
    cin >> t;
    for (ll k = 1; k <= t; k++)
    {
        ll n, m, i, j;

        ll x, y, c;
        cin >> x >> y >> c;
        if (c % gcd(x, y) == 0)
            cout << "Case " << k << ": "
                 << "Yes\n";
        else
            cout << "Case " << k << ": "
                 << "No\n";
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
