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


int findMaxUtil(node* root, int &res)
{
    if (root == NULL)
        return 0;
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);
    int max_single = max(max(l, r) + root->data, root->data);
    int max_top = max(max_single, l + r + root->data);
    res = max(res, max_top); 
 
    return max_single;
}
int findMaxSum(node *root)
{
    int res = INT_MIN;
    findMaxUtil(root, res);
    return res;
}
int main()
{
   cin.tie(nullptr);
   cout.tie(NULL);
   ios_base::sync_with_stdio(false);
   struct node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    
    cout << findMaxSum(root) << endl;
  return 0;
}
 
