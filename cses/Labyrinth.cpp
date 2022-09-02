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
ll a[100001];
ll b[5000100];
// ll vis[200005];
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

char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n, m;
vector<char> path;
bool isValid(int x, int y)
{

    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (ar[x][y] == '#' || vis[x][y] == true)
        return false;

    return true;
}
bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (ar[a][b] == 'B')
        {
            while (1)
            {
                path.push_back(br[a][b]);

                if (path.back() == 'L')
                    b++;
                if (path.back() == 'R')
                    b--;
                if (path.back() == 'U')
                    a++;
                if (path.back() == 'D')
                    a--;

                if (a == x && b == y)
                    break;
            }
            return true;
        }

        //left
        if (isValid(a, b - 1))
            br[a][b - 1] = 'L', q.push({a, b - 1}), vis[a][b - 1] = true;

        //right
        if (isValid(a, b + 1))
            br[a][b + 1] = 'R', q.push({a, b + 1}), vis[a][b + 1] = true;

        //up
        if (isValid(a - 1, b))
            br[a - 1][b] = 'U', q.push({a - 1, b}), vis[a - 1][b] = true;

        //down
        if (isValid(a + 1, b))
            br[a + 1][b] = 'D', q.push({a + 1, b}), vis[a + 1][b] = true;
    }

    return false;
}
void solve()

{
    cin >> n >> m;
    int x;
    int y;

    rep1(i, n)
        rep1(j, m)
    {
        cin >> ar[i][j];
        if (ar[i][j] == 'A')
            x = i, y = j;
    }

    if (bfs(x, y) == true)
    {
        cout << "YES" << endl
             << path.size() << endl;
        while (path.size() > 0)
            cout << path.back(), path.pop_back();
    }
    else
    {
        cout << "NO";
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
