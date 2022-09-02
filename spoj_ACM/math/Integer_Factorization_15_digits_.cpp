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
ll a[1000005], b[1000005];
ll vis[100001], dis[100001];
vector<ll> adj[100001];
char s[100001];
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
    llu n, cnt, i;
    while (1)
    {
        scanf("%llu", &n);
        if (!n)
            break;
        cnt = 0;
        while (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }
        if (cnt > 0)
            printf("2^%llu", cnt);
        i = 3;
        while (i * i <= n && n != 1)
        {
            cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt > 0)
                printf("%llu^%llu ", i, cnt);
            i += 2;
        }

        if (n > 1)
            printf("%llu^1", n);
        printf("\n");
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
