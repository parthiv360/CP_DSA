#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
#define pie acos(-1.0)
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef long long unsigned llu;
typedef pair<int,int>pi;
#define cin(a,n)        for(ll i=0;i<n;i++)cin>>a[i];
#define store(b,n)      for(int i=1;i<=n;i++)b[i]=a[i];
#define rep(i, y, z) for(int i = (y); i <(z); i++)
ll a[1000005],b[1000005],pos[1000005];


char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int N;
 
bool isValid(int x , int y)
{
	if(x > N || x < 1 || y > N || y < 1) return false;
	
	if(vis[x][y] || ar[x][y] == 'T') return false;
	
	return true;
}
 
void bfs(int srcX , int srcY)
{
	queue< pair<int,int> > q;
	q.push( {srcX , srcY} );
	dist[srcX][srcY] = 0;
	vis[srcX][srcY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			
			if(isValid(newX , newY))
			{
				dist[newX][newY] = d + 1;
				vis[newX][newY] = 1;
				q.push( {newX , newY} );
			}
		}
	}
	
}
 
int main()
{
	int srcX , srcY , endX , endY;
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>ar[i][j];
			if(ar[i][j] == 'S') srcX = i , srcY = j;
			if(ar[i][j] == 'E') endX = i , endY = j;
		}
	}
	
	bfs(srcX , srcY);
	cout<<dist[endX][endY];
}