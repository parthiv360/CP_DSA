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
ll seg_tree[4*200005];
ll build(ll si,ll s,ll e){
    if(s==e)
    return seg_tree[si]=ar[s];
    ll mid=(s+e)>>1;
    return seg_tree[si]=build(2*si,s,mid)^build(2*si+1,mid+1,e);
}
void update(ll si,ll s,ll e,ll ind, ll v){
    if(ind<s || ind>e)return;
    if(s==e && s==ind){
        seg_tree[si]+=v;
        return;
    }
    ll mid=(s+e)>>1;
    update(2*si,s,mid,ind,v);
    update(2*si+1,mid+1,e,ind,v);
    seg_tree[si]=min(seg_tree[2*si],seg_tree[2*si+1]);
}
ll getsum(ll si,ll s,ll e, ll l,ll r){
    if(l>e || r<s)return 0;
    if(s>=l and e<=r)
    return seg_tree[si];
    ll mid=(s+e)>>1;
    return getsum(2*si,s,mid,l,r)^getsum(2*si+1,mid+1,e,l,r);
}

// ENDS 
const int N = 3e5 + 10;
vector<int> gr[N], tin(N), tout(N), dep(N);
int up[N][20], timer;
 
void calc(int v, int pr = 1) {
	up[v][0] = pr;
	for(int i = 1; i < 20; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	for(auto it: gr[v]) {
		if(it != pr) {
			dep[it] = dep[v] + 1;	
			calc(it, v);
		}
	}
	tout[v] = timer++;
} 
 
bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
 
int lca(int a, int b) {
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = 19; i >= 0; i--) {
		if(!upper(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}
 
int dist(int a, int b) {
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
 
int getpar(int v, int l) {
	for(int i = 19; i >= 0; i--) {
  	if((1 << (i)) <= l) {
  		l -= (1 << (i));
  		v = up[v][i];
  	}
  }
  return v;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int l, r;
		cin >> l >> r;
		gr[l].pb(r);
		gr[r].pb(l);
	}
	calc(1);
	int q;
	cin >> q;
 
	while(q--) {
		int l, r;
		cin >> l >> r;
		int e;
		cin >> e;
		if(dist(l, r) <= e) {
			cout << r << endl;
		} else {
			int mid = lca(l, r);
			if(e < dist(l, mid)) {
				cout << getpar(l, e) << endl;
				continue;
			}
			if(e == dist(l, mid)) {
				cout << mid << endl;
				continue;
			}
			e -= dist(l, mid);
			e = dist(mid, r) - e;
			cout << getpar(r, e) << endl; 	
		}
	}
}