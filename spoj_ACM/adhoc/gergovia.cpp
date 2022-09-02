#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
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

void solve()
{
    while (1)
    {
        ll n, i, j;
        cin >> n;
        if (n == 0)
            break;
        cin(a, n);
        b[0] = a[0];
        for (i = 1; i < n; i++)
        {
            b[i] = a[i] + b[i - 1];
        }
        ll s = 0;
        rep(i, n)
        {
            if (b[i] < 0)
                s += (b[i] * -1);
            else
                s += b[i];
        }
        cout << s << endl;
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
