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
ll vis[200005], dis[200005];
ll fri[200005];
vector<ll> adj[200005];
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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll m1 = n / 2, m2 = n - m1;
    vector<ll> v1(m1), v2(m2);
    rep(i, m1)
            cin >>
        v1[i];
    rep(i, m2)
            cin >>
        v2[i];
    vector<ll> s1, s2;
    for (ll i = 0; i < (1 << m1); i++)
    {
        ll c = 0;
        for (ll j = 0; j < m1; j++)
        {
            if (i & (1 << j))
                c += v1[j];
        }
        s1.push_back(c);
    }
    for (ll i = 0; i < (1 << m2); i++)
    {
        ll c = 0;
        for (ll j = 0; j < m2; j++)
        {
            if (i & (1 << j))
                c += v2[j];
        }
        s2.push_back(c);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    ll ans = 0;
    for (ll i : s1)
    {
        ans += upper_bound(s2.begin(), s2.end(), k - i) - lower_bound(s2.begin(), s2.end(), k - i);
    }
    cout << ans;
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
