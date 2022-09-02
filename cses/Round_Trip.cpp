// ⋱C⋱r⋱i⋱s⋱t⋱i⋱a⋱n⋱o⋱⋱⋱R⋱o⋱n⋱a⋱l⋱d⋱o⋱.⋱.⋱.⋱.⋱.⋱.⋱G⋱O⋱A⋱T

// P⋱a⋱r⋱t⋱h⋱i⋱v⋱⋱⋱S⋱a⋱r⋱k⋱a⋱r
// ⋱

#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
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
ll vis[200005], par[200005];
vector<ll> adj[200005];
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

ll n = 0, k, m = 0;
ll start, ed;

bool dfs(ll node, ll p)
{
    vis[node] = 1;
    par[node] = p;
    for (ll ch : adj[node])
    {
        if (ch == p)
            continue;
        if (vis[ch] == 1)
        {
            start = ch;
            ed = node;
            return true;
        }
        if (vis[ch] == 0)
        {
            if (dfs(ch, node))
                return true;
        }
    }
    return false;
}
bool check()
{
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}
void solve()

{
    cin >> n >> m;
    rep1(i, m)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (!check())
    {
        cout << "IMPOSSIBLE";
        return;
    }
    ll val = ed;
    vector<ll> ans;
    ans.push_back(ed);
    while (val != start)
    {
        ans.push_back(par[val]);
        val = par[val];
    }
    ans.push_back(ed);
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c << " ";
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
