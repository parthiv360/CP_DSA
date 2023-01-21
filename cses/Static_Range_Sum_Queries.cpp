// ⋱C⋱r⋱i⋱s⋱t⋱i⋱a⋱n⋱o⋱⋱⋱R⋱o⋱n⋱a⋱l⋱d⋱o⋱.⋱.⋱.⋱.⋱.⋱.⋱G⋱O⋱A⋱T

// P⋱a⋱r⋱t⋱h⋱i⋱v⋱⋱⋱S⋱a⋱r⋱k⋱a⋱r
// ⋱

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const long long inf = 1e18;
#define mod 1000000007
#define mod1 998244353
#define maxn 5000000
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, n) for (lli i = a; i < n; i++)
#define rrep(i, n, a) for (lli i = n; i >= a; i--)
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef unsigned long long int llu;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pl;
typedef vector<pl> vp;
typedef tree <
	ll,
	null_type,
    less<ll>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;// find_by_order,order_of_key

#define cin(a, n)              \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define store(b, n)             \
    for (int i = 0; i < n; i++) \
        b[i] = a[i];
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define line cout << endl
ll a[5000100];
ll b[5000100];
ll vis[200005];
vll adj[400005];
vll fact(2000009);
vector<bool> isprime;
vll primes;
int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 string ds="RLDU";
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

ll n = 0, k, m = 0;

void solve()

{
    ll i, j;

    cin >> n >>m;
    vll v(n+1);
    v[0]=0;
    rep(i,1,n+1)
    {
        ll x;
        cin>>x;
        v[i]=v[i-1]+x;
    }
    rep(i,0,m){
        ll x,y;
        cin>>x>>y;
        cout << v[y]-v[x-1] << endl;
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
