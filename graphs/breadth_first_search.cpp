#include <bits/stdc++.h>
using namespace std;

#define display(arr,s,e) for(i=s; i<=e; i++) cout<<arr[i]<<" ";
#define mset(arr,x) memset(arr,x,sizeof(arr))

#define MOD 1000000007
#define epsilon 0.000000000001
#define I_MAX 9223372036854775807
#define I_MIN -9223372036854775807

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)
#define endl "\n"

#define ll long long
#define mid(a,b) ((a)+((b-a)/2))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// Useful STL commands:
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define si set<int>
#define vi vector<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define all(c) c.begin(),c.end()
#define tr(c,it) for(auto it=c.begin();it!=c.end();++it)

#define DEBUG
// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

ll gcd(ll a, ll b)
{
    if( (a == 0) || (b == 0) )
        return a + b;
    return gcd(b, a % b);
}

ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res;
}

bool isPrime(ll a)
{
    for(int i=3; (i*i)<=a; i+=2)
    {
        if( (a%i)==0 )
        {
            return false;
        }
    }
    return true;
}

vi vc[500], vc2[500];
bool visited[500], visited2[500];
int level[500], level2[500];
map< pair<int, int>, int > ma;

void bfs( int so )
{
    int opop, i, upup, kkl;
    queue< int > qu;
    qu.push( so );
    visited[ so ] = 1;
    level[ so ] = 0;

    while( !qu.empty() )
    {
      opop = qu.front();
      qu.pop();
      upup = vc[opop].size();

      rep(i, 0, upup-1)
      {
         kkl = vc[opop][i];
         if( !visited[ kkl ] )
         {
           visited[ kkl ] = 1;
           qu.push( kkl );
           level[ kkl ] = level[ opop ] + 1;
         }
      }
    }
}
void bfs2( int so )
{
    int opop, i, upup, kkl;
    rep(i, 0, 405)
    {
      level2[ i ] = INT_MAX;
    }

    queue< int > qu;
    qu.push( so );
    level2[ so ] = 0;
    visited2[ so ] = 1;

    while( !qu.empty() )
    {
      opop = qu.front();
      qu.pop();
      upup = vc2[opop].size();

      rep(i, 0, upup-1)
      {
         kkl = vc2[opop][i];
         visited2[ kkl ] = 1;

         if( level2[ kkl ] > ( level2[opop]+1 ) )
         {
           qu.push( kkl );
           level2[ kkl ] = level2[ opop ] + 1;
         }
      }
    }
}

int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, i, U, V, j;

    cin >> N >> M;
    rep(i, 1, N)
    {
       rep(j, 1, N)
       {
          ma[ mp(i, j) ] = 0;
       }
    }
    rep(i, 0, M-1)
    {
       cin >> U >> V;
       vc[ U ].pb( V );
       vc[ V ].pb( U );

       ma[ mp( U, V ) ] = 1;
       ma[ mp( V, U ) ] = 1;
    }
    rep(i, 1, N)
    {
       rep(j, 1, N)
       {
          if( !ma[ mp(i, j) ]  && (i!=j) )
          {
             vc2[i].pb( j );
          }
       }
    }

    if( N==2 )
    {
       cout << "-1";
       return 0;
    }

    bfs(1);
    if( !visited[N] )
    {
       cout << "-1";
       return 0;
    }

    if( !ma[ mp(1, N) ] )
    {
       cout << level[ N ];
       return 0;
    }

    bfs2(1);
    if( !visited2[N] )
    {
       cout << "-1";
       return 0;
    }
    cout << level2[N];

    return 0;
}
