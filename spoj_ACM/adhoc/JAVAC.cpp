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

bool java(string s)
{
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] == '_')
            return false;
    if (s[0] <= 'Z')
        return false;
    return true;
}
bool cpp(string s)
{
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] <= 'Z')
            return false;
    if (s[0] == '_')
        return false;
    if (s[s.length() - 1] == '_')
        return false;
    for (i = 0; i < s.length() - 2; i++)
        if (s[i] == '_' && s[i + 1] == '_')
            return false;
    return true;
}
string translate_to_cpp(string s) //Java to C++
{
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] <= 'Z')
        {
            char c = s[i];
            s.insert(i, "_");
            s[i + 1] = c + 32;
        }
    return s;
}
string translate_to_java(string s) //C++ to Java
{
    int i;
    for (i = 0; i < s.length(); i++)
        if (s[i] == '_')
        {
            s.erase(i, 1);
            s[i] = s[i] - 32;
        }
    return s;
}
void solve()
{
    string s;
    while (!cin.eof())
    {
        cin >> s;
        if (java(s))
            cout << translate_to_cpp(s) << endl;
        else if (cpp(s))
            cout << translate_to_java(s) << endl;
        else
            cout << "Error!\n";
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
