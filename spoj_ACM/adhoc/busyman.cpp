#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
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
    ll n, i, j;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    ll x, y;
    rep(i, n)
    {
        cin >> x >> y;
        vp[i] = {y, x};
    }
    sort(vp.begin(), vp.end());
    ll cnt = 1;
    ll end = vp[0].first;
    for (i = 1; i < n; i++)
    {
        if (vp[i].second >= end)
        {
            cnt++;
            end = vp[i].first;
        }
    }
    cout << cnt << endl;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
