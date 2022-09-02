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

    ll n, m, i, j;
    cin >> n >> m;
    int t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll xd, xm, yd;
        xd = min(x2 + abs(y1 - y2), x3 + abs(y1 - y3));
        xm = max(x2 - abs(y1 - y2), x3 - abs(y1 - y3));
        yd = min(y2 + abs(x1 - x2), y3 + abs(x1 - x3));
        if (x1 < xd or y1 < yd or x1 > xm)
            cout << "YES\n";
        else
            cout << "NO\n";
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
