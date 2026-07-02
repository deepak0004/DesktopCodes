// memory taken should be less as it might give RE (SIGSEGV)

#include <bits/stdc++.h>/
using namespace std;

#define display(arr,s,e) for(i=s; i<=e; i++) cout<<arr[i]<<" ";
#define mset(arr,x) memset(arr,x,sizeof(arr))
#define MOD 1000000007
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
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

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

ll K[1010][1010], weig[1010], beau[1010], tempwe, tempbe;
bool vis[1010];
vector< pair< ll, ll > > vc[1010];
vector<ll> adj[1010];
void dfs( ll src, ll par, ll opop )
{
    ll i, h;
    vis[src] = 1;
    vc[opop].pb( mp(weig[src], beau[src]) );
    h = adj[src].size();
    tempbe += beau[src];
    tempwe += weig[src];
    for(i=0; i<h; i++)
    {
        ll xx = adj[src][i];
        if( vis[ xx ] || xx==par )
        {
            continue;
        }
        dfs(xx, src, opop);
    }
}
ll knapSack(ll W, vector< pair< ll, ll > > vc[], ll n)
{
   ll i, w, h, kk;

   // Build table K[][] in bottom up manner
   for( i=1; i<=n; i++)
   {
       h = vc[i-1].size();
       for(kk=0; kk<h; kk++)
       {
            for(w=1; w<=W; w++)
            {
                 if( vc[i-1][kk].f<=w )
                 {
                     K[i][w] = max( vc[i-1][kk].s + K[i-1][w-vc[i-1][kk].f],  max(K[i-1][w], K[i][w]) );  // max(ith item included, ith item not included, ith prev iem included)
                 }
                 else
                 {
                      K[i][w] = max(K[i][w], K[i-1][w]);
                 }
            }
       }
   }

   return K[n][W];
}
int main()
{
    #ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j, N, W, M, AA, BB;

    cin >> N >> M >> W;
    rep(i, 1, N)
    {
        cin >> weig[i];
    }
    rep(i, 1, N)
    {
        cin >> beau[i];
    }
    rep(i, 1, M)
    {
        cin >> AA >> BB;
        adj[AA].pb( BB );
        adj[BB].pb( AA );
    }
    ll opop = 0;
    rep(i, 1, N)
    {
      if( !vis[i] )
      {
          tempwe = 0;
          tempbe = 0;
          dfs(i, -1, opop);
          if( vc[opop].size()>=2 )
             vc[opop].pb( mp(tempwe, tempbe) );
          opop++;
      }
    }

    cout << knapSack(W, vc, opop);

    return 0;
}
