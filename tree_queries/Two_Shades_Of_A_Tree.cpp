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
// SEGMENT TREE IMPLEMENTATION BEGINS ......

ll ar[200005];
ll seg_tree[4*200005],lazy[4*200005];
void build(ll si,ll s,ll e){
    if(s > e) return;
    seg_tree[si] = e-s+1;
    if(s == e) return;

    ll mid = (s+e)/2;
    build(2*si, s, mid);
    build(2*si+1, mid+1, e);
}
void update(ll si,ll s,ll e){
    if(lazy[si] == 0) return;
    seg_tree[si] = (e-s+1)-seg_tree[si];

    if(s < e){
        lazy[2*si] ^= 1;
        lazy[2*si+1] ^= 1;
    }
    lazy[si] = 0;
}
ll query(ll si,ll s,ll e, ll L,ll R){
    update(si, s, e);
    if(e < L or R < s) return 0;
    if(L <= s and e <= R) return seg_tree[si];

    ll mid = (s+e)/2;
    return query(2*si, s, mid, L, R)+query(2*si+1, mid+1, e, L, R);
}
void flip(ll n, ll l, ll r, ll L, ll R){
        update(n, l, r);
        if(r < L or R < l) return;
        if(L <= l and r <= R){
            lazy[n] ^= 1;
            update(n, l, r);
            return;
        }

        ll mid = (l+r)/2;
        flip(2*n, l, mid, L, R);
        flip(2*n+1, mid+1, r, L, R);
        seg_tree[n] = seg_tree[2*n]+seg_tree[2*n+1];
    }
// ENDS

// Fenwich tree
struct BIT {
	vector<ll> bit;
	ll n;
	BIT(ll n) : n(n + 1), bit(n + 1) {}
	ll sum(ll r) {
		r++;
		ll ret = 0;
		while (r > 0) {
			ret += bit[r];
			r -= r & -r;
		}
		return ret;
	}
	void update(ll idx, ll v) {
		idx++;
		while (idx < n) {
			bit[idx] += v;
			idx += idx & -idx;
		}
	}
};

//  Ends


ll n = 0, k, m = 0;
vll tin(200005),tout(200005);
ll tim=0;
void dfs(ll node,ll p){
    tin[node]=tim++;
    for(auto it: adj[node]){
        if(it==p)
        continue;
        dfs(it,node);
    }
    tout[node]=tim-1;
}
void solve()

{
    ll i, j;
    cin>>n;
    rep(i,1,n){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0,-1);
    build(1,0,n-1);
    // for(i=0;i<=n-1;i++){
    //     cout << tin[i] << " " << tout[i]<< endl;
    // }
    cin>>m;

    while(m--){
        ll p;
        cin>>p;
        if(p==1){
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            if(tin[u]>tin[v])
            swap(u,v);
            ll b1=query(1,0,n-1,tin[v],tout[v]);
            ll b2=query(1,0,n-1,0,n-1)-b1;
            cout << b1*b2 << endl;
        }
        else{
            ll u;
            cin>>u;
            u--;
            flip(1,0,n-1,tin[u],tout[u]);
        }
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
