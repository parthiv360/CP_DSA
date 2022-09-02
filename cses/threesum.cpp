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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pair<int, int> p;
        p.first = a;
        p.second = i;
        // first in pair represents value, second represents index
        arr.push_back(p);
    }
    sort(begin(arr), end(arr));
    for (int i = 0; i < n; i++)
    {
        int l, r;
        l = 0;
        r = n - 1;
        while (l != r)
        {
            int target;
            target = x - arr.at(i).first;
            if (l != i && r != i && arr.at(l).first + arr.at(r).first == target)
            {
                cout << arr.at(i).second << " " << arr.at(l).second
                     << " " << arr.at(r).second << endl;
                return;
            }
            if (arr.at(l).first + arr.at(r).first < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
