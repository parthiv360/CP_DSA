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

const int N = 200001;

int _rank[N];
int par[N];

int find(int a)
{
    if (par[a] == -1)
        return a;

    return par[a] = find(par[a]);
}

int merge(int a, int b)
{

    a = find(a);
    b = find(b);

    if (_rank[a] < _rank[b])
        swap(a, b);

    par[b] = a;
    _rank[a] += _rank[b];

    return _rank[a];
}

int main()
{
    int n, a, b, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        _rank[i] = 1, par[i] = -1;

    int cc = n;
    int mx = 1;

    while (m--)
    {
        cin >> a >> b;

        if (find(a) != find(b))
            mx = max(mx, merge(a, b)), cc--;

        cout << cc << " " << mx << endl;
    }
}
