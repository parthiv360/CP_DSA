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
// char s[100001];

void solve()
{

    char s[600], num[10], result[600], enc[50];
    cin >> num;
    cin >> s;
    int len_num = strlen(num), i = 0, count, j = 0, k = 0, l;
    l = len_num - 1;
    k = len_num;
    while (num[i] != '\0')
    {
        enc[j++] = num[i++];
        enc[k++] = num[l--];
    }
    enc[k] = '\0';
    i = 0;
    k = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (count > (2 * len_num - 1))
            count = 0;
        j = s[i] - (enc[count] - 48);
        if (j < 97)
            result[k++] = 26 + j;
        else
            result[k++] = j;
        i++;
        count++;
    }
    result[k] = '\0';
    printf("%s\n", result);
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
