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
int dx[] = {1, 0, 0, -1}; // Four Directions
int dy[] = {0, -1, 1, 0}; // Four directions
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

bool cmp(const pair<ll, ll> &a,
         const pair<ll, ll> &b)
{
    return (a.second < b.second);
}
bool notPalindrome(string a){
    string b = a;
    reverse(b.begin(),b.end());
    return b != a;
}
ll helper(string prev, ll index, string& s, map<pair<ll, string>, ll>& dp){
    if(index == s.size()){
        return 1;
    }
    if(dp.find({index, prev}) != dp.end()){
        return dp[{index, prev}];
    }
    string x1 = prev.substr(1, 4);
    string x2 = prev.substr(1, 4);
    x1 += '0';
    x2 += '1';
    ll ans = 0;
    if(s[index] == '?'){
        if(notPalindrome(x1) && notPalindrome(prev + "0"))
            ans += helper(x1, index + 1, s, dp);
        if(notPalindrome(x2) && notPalindrome(prev + "1"))
            ans += helper(x2, index + 1, s, dp);
    }else if(s[index] == '1'){
        if(notPalindrome(x2) && notPalindrome(prev + "1"))
            ans += helper(x2, index + 1, s, dp);
    }else{
        if(notPalindrome(x1) && notPalindrome(prev + "0"))
            ans += helper(x1, index + 1, s, dp);
    }
    dp[{index, prev}] = ans;
    return ans;
}

void solve()

{
    ll T;
    cin >> T;
    rep(I, 1, T + 1)
    {

        ll i, j;
        cin>>n;
        string s;
        cin>>s;
        map<pair<ll,string>,ll>dp;
        cout << "Case #" << I << ": " << (helper("?????", 0, s, dp) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
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
