// ⋱C⋱r⋱i⋱s⋱t⋱i⋱a⋱n⋱o⋱⋱⋱R⋱o⋱n⋱a⋱l⋱d⋱o⋱.⋱.⋱.⋱.⋱.⋱.⋱G⋱O⋱A⋱T

// P⋱a⋱r⋱t⋱h⋱i⋱v⋱⋱⋱S⋱a⋱r⋱k⋱a⋱r
// ⋱

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod1 998244353
#define maxn 5000000
#define pb push_back
#define ff first
#define ss second
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
#define store(b, n)             \
    for (int i = 0; i < n; i++) \
        b[i] = a[i];
ll a[5000100];
ll b[5000100];
ll vis[300001], col[300001];
vector<ll> adj[300001];
vector<ll> fact(2000009);
vector<bool> isprime;
vector<ll> primes;

void sieve(ll n)
{
    if ((ll)isprime.size() >= n + 1)
        return;
    isprime.assign(n + 1, true);
    isprime[0] = isprime[1] = false;
    ll sqrtn = (ll)(sqrt(n * 1.) + .5);
    for (ll i = 2; i <= sqrtn; i++)
        if (isprime[i])
        {
            for (ll j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    primes.clear();
    for (ll i = 2; i <= n; i++)
        if (isprime[i])
            primes.push_back(i);
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
    x = (x % mod1);
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans % mod1) * (x % mod1)) % mod1;
        x = ((x % mod1) * (x % mod1)) % mod1;
        y >>= 1;
    }
    return ans % mod1;
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

ll n, k, m;
pair<ll, ll> bfs(ll node)
{
    queue<pair<ll, ll>> q;
    q.push({node, 0});
    pair<ll, ll> p;
    while (!q.empty())
    {
        p = q.front();
        vis[p.ff] = 1;
        q.pop();
        for (ll child : adj[p.ff])
        {
            if (vis[child] == 0)
                q.push({child, p.ss + 1});
        }
    }
    return p;
}
void solve()
{
    cin >> n;
    for (ll i = 1; i <= n - 1; i++)
    {
        cin >> k >> m;
        adj[k].pb(m);
        adj[m].pb(k);
    }
    pair<ll, ll> e1 = bfs(1);
    for (ll i = 1; i <= n; i++)
        vis[i] = 0;
    pair<ll, ll> e2 = bfs(e1.ff);
    cout << e2.ss << endl;
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
