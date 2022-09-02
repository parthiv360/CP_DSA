#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
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
    ll n, x, i, j;
    cin >> n >> x;
    cin(a, n);
    map<ll, ll> mp;

    ll res = 0;
    mp[0] = 1;
    ll currsum = 0;

    rep(i, n)
    {
        currsum += a[i];
        if (mp.find(currsum - x) != mp.end())
            res += mp[currsum - x];
        mp[currsum]++;
    }
    cout << res << endl;
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
