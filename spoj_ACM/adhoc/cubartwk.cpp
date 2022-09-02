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
    int w, h, num, result, heights1[21], heights2[21];
    while (true)
    {
        scanf("%d%d", &w, &h);
        if (w == 0 && h == 0)
            break;
        result = 0;
        fill(heights1, heights1 + 21, 0);
        fill(heights2, heights2 + 21, 0);
        for (int i = 0; i < w; i++)
        {
            scanf("%d", &num);
            heights1[num]++;
        }
        for (int i = 0; i < h; i++)
        {
            scanf("%d", &num);
            heights2[num]++;
        }
        for (int i = 1; i < 21; i++)
        {
            int common = min(heights1[i], heights2[i]);
            result += (common * i);
            heights1[i] -= common;
            heights2[i] -= common;
            result += (heights1[i] * i) + (heights2[i] * i);
        }
        printf("%d\n", result);
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
