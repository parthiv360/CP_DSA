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
typedef vector<ll> vll;
typedef pair<ll, ll> pl;
typedef vector<pl> vp;
#define blk 500
#define cin(a, n)               \
    for (ll i = 1; i <= n; i++) \
        cin >> a[i];
#define store(b, n)             \
    for (int i = 0; i < n; i++) \
        b[i] = a[i];
ll a[5000100];
ll b[5000100];
ll vis[200005];
vector<ll> adj[400005];
vector<ll> fact(2000009);
vector<bool> isprime;
vector<ll> primes;
int dx[] = {1, 0, 0, -1}; //Four Directions
int dy[] = {0, -1, 1, 0}; //Four directions
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

struct query
{
    int l;
    int r;
    int i;
};
query Q[300001];
int ar[300001], ans[300001];
int fre[300001];

int freOfFre[300001];
int currMax = 0;

bool comp(query a, query b)
{
    if (a.l / blk != b.l / blk)
        return a.l / blk < b.l / blk;

    return a.r < b.r;
}

void add(int pos)
{
    int preF = fre[ar[pos]];
    fre[ar[pos]]++;
    int currF = fre[ar[pos]];

    freOfFre[preF]--;
    freOfFre[currF]++;

    if (currF > currMax)
    {
        currMax = currF;
    }
}

void remove(int pos)
{
    int preF = fre[ar[pos]];
    fre[ar[pos]]--;
    int currF = fre[ar[pos]];

    freOfFre[preF]--;
    freOfFre[currF]++;

    if (currF < currMax)
    {
        while (freOfFre[currMax] == 0)
            currMax--;
    }
}

void solve()
{

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i, Q[i].l--, Q[i].r--;
    }

    sort(Q, Q + q, comp);
    int ML = 0, MR = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L)
            ML--, add(ML);

        while (MR < R)
            MR++, add(MR);

        while (ML < L)
            remove(ML), ML++;

        while (MR > R)
            remove(MR), MR--;

        int total = Q[i].r - Q[i].l + 1;
        int rem = total - currMax;
        int half = (total + 1) / 2;

        if (currMax <= half)
            ans[Q[i].i] = 1;
        else
        {
            ans[Q[i].i] = total - 2 * rem;
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
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
