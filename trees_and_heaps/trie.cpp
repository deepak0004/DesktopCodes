/*
Author : deepak2015
I am a coder.
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

ll num;
struct trie
{
   trie *next[2];  // array of pointers to next level trie nodes.
   ll coun;
   trie()
   {
     next[0] = NULL;
     next[1] = NULL;
     coun = 1;
   }
};
void insertt( trie *poin )
{
   ll i;
   rrep(i, 31, 0)
   {
       ll opop = ( 1LL<<i );
       if( !poin->next[(opop&num)>=1] )
       {
          poin->next[(opop&num)>=1] = new trie;
          poin = poin->next[(opop&num)>=1];
       }
       else
       {
          (poin->next[(opop&num)>=1])->coun++;
          poin = poin->next[(opop&num)>=1];
       }
   }
}
void deletee( trie *poin )
{
   ll i;
   rrep(i, 31, 0)
   {
       ll opop = ( 1LL<<i );
       (poin->next[(opop&num)>=1])->coun--;
       if( !(poin->next[(opop&num)>=1])->coun )
       {
         poin->next[(opop&num)>=1] = NULL;
       //  trace1(opop)
         return;
       }
       poin = poin->next[(opop&num)>=1];
   }
}
ll maxx( trie *poin )
{
   ll i, N, maxi = 0;
   rrep(i, 31, 0)
   {
       ll opop = ( 1LL<<i );
       if( poin->next[1 - ((opop&num)>=1)] )
       {
          if( !(opop&num) )
          {
              maxi = maxi^opop;
          }
          poin = poin->next[1 - ((opop&num)>=1)];
       }
       else
       {
          if( opop&num )
          {
              maxi = maxi^opop;
          }
          poin = poin->next[(opop&num)>=1];
       }
   }

   return maxi;
}

int main()
{
        #ifndef  ONLINE_JUDGE
            freopen("input.txt","r",stdin);
        #endif

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        ll i, Q;
        string stt;

        struct trie *root = new trie;

        cin >> Q;
        insertt( root );
        while( Q-- )
        {
            cin >> stt;
            if( stt=="+" )
            {
                cin >> num;
                insertt( root );
            }
            else if( stt=="-" )
            {
                cin >> num;
                deletee( root );
            }
            else
            {
                cin >> num;
                cout << (maxx( root )^num) << endl;
            }
        }

        return 0;
}

/*
8
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3


   1      0
   |      |\
   0      1 0
   |\     | |
   0 1    1 0
   |\ \   | |
   0 1 1  0 1
*/
