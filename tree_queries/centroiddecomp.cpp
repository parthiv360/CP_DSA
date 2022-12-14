#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
using namespace std;
set<int> ar[100001];
int par[100001];
int sub[100001];
//--------Decompose Part-----------//

int dfs1(int node, int p)
{
    sub[node] = 1;

    for (int adj : ar[node])
        if (adj != p)
            sub[node] += dfs1(adj, node);

    return sub[node];
}

int dfs(int node, int p, int n)
{
    for (int adj : ar[node])
        if (adj != p && sub[adj] > n / 2)
            return dfs(adj, node, n);

    return node;
}

void decompose(int node, int p)
{

    int subTreeSize = dfs1(node, -1);

    int centroid = dfs(node, p, subTreeSize);

    cout << "tree rooted at " << node << " with size " << subTreeSize << " has centroid " << centroid << endl;

    par[centroid] = p;

    for (int adj : ar[centroid])
        ar[adj].erase(centroid), decompose(adj, centroid);
}

//---------- decompose ends here -----------//

int main()
{

    int n, x, y;
    cin >> n;

    REP(i, n - 1)
    cin >> x >> y,
        ar[x].insert(y), ar[y].insert(x);

    decompose(1, -1);

    cout << "Parent array is as follows\n";
    REP(i, n)
    cout << "\tPar[" << i << "] = " << par[i] << endl;
}
