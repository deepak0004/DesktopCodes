/*
Author : deepak2015
Plagiarism is bad.
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define epsilon 0.000000000001
#define PI 3.1415926535897932
#define I_MAX 9223372036854775807
#define I_MIN -9223372036854775807
#define ll long long
#define endl "\n"

#define mset(arr,x) memset(arr,x,sizeof(arr))
#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// Useful STL commands:
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define tr(c,it) for(auto it=c.begin();it!=c.end();++it)
#define trrev(c,it) for(auto it=c.rbegin();it!=c.rend();++it)

#define DEBUG
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#endif

// data type for individual node in the segment tree
struct node
{
   // stores sum of the elements in node
   int no_of_books;

   string arr;

   // pointer to left and right children
   node *left, *right;

   node(node *l, node *r, int books, int M)
   {
     int i;
     rep(i, 1, M+10)
     {
         arr.pb('0');
     }
     left = l;
     right = r;
     no_of_books = books;
   }
};
// root pointers for all versions
node *version[100010];
ll N, M, Q;

// Constructs Version-0
// Time Complexity : O(nlogn)
void build(node* n,int low,int high)
{
    if (low==high)
    {
        return;
    }
    int mid = (low+high) / 2;
    n->left = new node(NULL, NULL, 0, M);
    n->right = new node(NULL, NULL, 0, M);
    build(n->left, low, mid);
    build(n->right, mid+1, high);
    n->no_of_books = n->left->no_of_books + n->right->no_of_books;
}

/**
 * Upgrades to new Version
 * @param prev : points to node of previous version
 * @param cur  : points to node of current version
 * Time Complexity : O(logn)
 * Space Complexity : O(logn)  */
void upgrade(node *prev, node *cur, int low, int high, int idx, int ind_of_ind, int value)
{
    if( idx>high || idx<low || low>high )
        return;

    int i, j;
    if( low==high )
    {
        int i;
        rep(i, 1, M)
            cur->arr = prev->arr;
        cur->no_of_books = prev->no_of_books;

        //trace2(prev->arr[2], value)
        if( value==1 )
        {
           // modification in new version
           if( cur->arr[ind_of_ind]=='0' )
               cur->no_of_books++;

           cur->arr[ind_of_ind] = '1';
        }
        else if( value==2 )
        {
           if( cur->arr[ind_of_ind]=='1' )
               cur->no_of_books--;

           cur->arr[ind_of_ind] = '0';
         //  trace2(cur->no_of_books, value)
        }
        else
        {
           int su = 0;
           rep(i, 1, ind_of_ind)
           {
               if( cur->arr[i]=='0' )
               {
                   su++;
                   cur->arr[i] = '1';
               }
               else
               {
                   su--;
                   cur->arr[i] = '0';
               }
           }

           cur->no_of_books += su;
         //  trace2(cur->no_of_books, value)
        }

        return;
    }

    int mid = ( low + high )/2;
    //trace4(low, high, mid, idx)
    if( idx<=mid )
    {
        // link to right child of previous version
        cur->right = prev->right;
        // create new node in current version
        cur->left = new node(NULL, NULL, 0, M);
        upgrade(prev->left, cur->left, low, mid, idx, ind_of_ind, value);
    }
    else
    {
        // link to left child of previous version
        cur->left = prev->left;
        // create new node for current version
        cur->right = new node(NULL, NULL, 0, M);
        upgrade(prev->right, cur->right, mid+1, high, idx, ind_of_ind, value);
    }

    // calculating data for current version by combining previous version and current modification
    cur->no_of_books = (cur->left)->no_of_books + (cur->right)->no_of_books;
}
//int query(node *n, int low, int high, int l, int r)
//{
//    if( l>high or r<low or low>high)
//       return 0;
//    if( l<=low and high<=r )
//       return n->val;
//    int mid = (low+high) / 2;
//    int p1 = query(n->left,low,mid,l,r);
//    int p2 = query(n->right,mid+1,high,l,r);
//
//    return p1+p2;
//}

int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j, K, A, X, Y, lev = 1;
    string st;

    cin >> N >> M >> Q;

    // creating Version-0
    node *root = new node(NULL, NULL, 0, M);
    build(root, 1, N);

    // storing root node for version-0
    version[0] = root;

    while( Q-- )
    {
        cin >> A;
      //  trace1(A)
        if( A==1 || A==2 )
        {
            // upgrading to version new(1, 2, ...)
            version[lev] = new node(NULL, NULL, 0, M);
            cin >> X >> Y;

            if( A==1 )
            {
                upgrade(version[lev-1], version[lev], 1, N, X, Y, 1);
            }
            else
            {
                upgrade(version[lev-1], version[lev], 1, N, X, Y, 2);
            }

            cout << version[lev]->no_of_books << endl;
            lev++;
        }
        else
        {
            cin >> K;
            version[lev] = new node(NULL, NULL, 0, M);
            if( A==3 )
            {
                upgrade(version[lev-1], version[lev], 1, N, K, M, 3);
            }
            else
            {
                version[lev] = version[K];
            }

            cout << version[lev]->no_of_books << endl;
            lev++;
        }
    }

    return 0;
}
