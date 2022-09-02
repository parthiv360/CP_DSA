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
pi arr[1000005];
int dp[1005][1005];

struct node {
    int data;
    struct node *left, *right;
};

// struct node* newNode(int data);

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return (node);
}
int diameterOpt(struct node* root, int* height)
{
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;
  
    if (root == NULL) {
        *height = 0;
        return 0; 
    }
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
    *height = max(lh, rh) + 1;
  
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int height=0;
    cout << diameterOpt(root, &height) << endl;
  return 0;
}
 
