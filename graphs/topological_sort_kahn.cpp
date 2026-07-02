/*
Author : deepak2015
I am a coder.
https://github.com/nirwandogra/Spoj-Solutions/blob/master/TOPOSORT-10253667.cpp
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

double tick()
{
    static clock_t oldtick; clock_t newtick = clock();
    double diff = 1.0*(newtick - oldtick) / CLOCKS_PER_SEC;
    oldtick = newtick;
    return diff;
}

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
            return false;
    }
    if( ( a!=2 ) && ( (a%2)==0 ) )
        return false;
    return true;
}
string con_ll_to_str( ll a )
{
    stringstream mystr;
    mystr << a;
    return mystr.str();
}
ll con_str_to_ll( string st )
{
    ll numb = 0;
    int len = st.size(), i, j = 0;
    rrep(i, len-1, 0)
    {
       numb += ( pow_mod(10, j) * ( st[i] - '0' ) );
       j++;
    }
    return numb;
}

// Remember that set and map have the member functions find() and count(), which works in O(log N).
// tick() can be here or there so don't deter and submit it. Check it always on ideone.
/*
struct comp
{
    inline bool operator()(const pair<pair<ll, int>, bool>& pa1, const pair<pair<ll, int>, bool>& pa2) const
    {
        if (pa1.f.f == pa2.f.f)
            return pa1.f.s < pa2.f.s;
        return pa1.f.f < pa2.f.f;
    }
};
*/
// bitset<99999000000000>& c = *(new bitset<99999000000000>());   // For O(1) lookup the max bitset space required.
// Don't use map in qsort comp, instead store value in vector in form of pair. It is because it takes n*log(n)*log(n) time that increases the complexity.
// cout << fixed << setprecision(12) << ans;  // For 12 decimal places after the number.
// vector iterators can only be compared.

stack< ll > stac;
bool vis[ 40000 ], minvis[ 40000 ];
vector< ll > vc[ 40010 ], vc2[ 40010 ];
ll PP[ 40010 ], indeg[ 40010 ];
set< int >  nextNode;
vector< int > order;
//void topo_sort( ll ind, ll par )
//{
//  ll i;
//  vis[ ind ] = 1;
//  rep(i, 0, (int)vc[ind].size()-1)
//  {
//      if( !vis[ vc[ind][i] ] )
//      {
//          topo_sort( vc[ind][i], ind );
//      }
//  }
//
//  stac.push( ind );
//  return;
//}
void topology()
{
	int u, v, i;
	set< int >::iterator it;
	while(!nextNode.empty())
    {
		u = *nextNode.begin();
		nextNode.erase( nextNode.begin() );
		order.pb(u);
		for(i=0; i!=vc[u].size(); i++)
        {
			v = vc[u][i];
			indeg[v]--;
			if(!indeg[v])
			   nextNode.insert(v);
		}
	}
}
void dfs(ll src, ll par)
{
    minvis[src] = 1;
    ll h = vc2[src].size(), i, xx;
    rep(i, 0, h-1)
    {
        xx = vc2[src][i];
        if( ( minvis[xx]==1 ) || ( xx==par ) )
        {
            continue;
        }
        dfs(xx, src);
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, i, j, X, Y, D, Q;

    cin >> Q;
    while(Q--)
    {
        nextNode.clear();
        order.clear();
        vector<ll> anss;
        cin >> N >> M;
        rep(i, 1, N)
        {
            cin >> D;
            indeg[i] = D;
            while( D-- )
            {
               cin >> X;     // X  ------ > i is a dependency
               vc[X].pb(i);
               vc2[i].pb(X);
            }

        }
        rep(i, 1, M)
        {
            cin >> PP[i];
        }
//        rep(i, 1, N)
//        {
//            sort( all(vc[i]) );
//        }
//        rrep(i, N, 1)
//        {
//            if( !vis[i] )
//            {
//                topo_sort( i, -1 );
//            }
//        }
      	for(i=1; i<=N; i++)
		{
		    if(!indeg[i])
			   nextNode.insert(i);
        }
        topology();
        rep(i, 1, M)
        {
            if( !minvis[ PP[i] ] )
            {
                dfs( PP[i], -1 );
            }
        }
        rep(i, 0, (int)order.size()-1)
        {
            if( minvis[ order[i] ] )
            {
                anss.pb( order[i] );
            }
        }
        cout << anss.size() << endl;
        rep(i, 0, (int)anss.size()-1)
        {
            cout << anss[i] << " ";
        }
        cout << endl;
        rep(i, 1, N)
        {
            vc[i].clear();
            vc2[i].clear();
            PP[i] = 0;
            vis[i] = 0;
            minvis[i] = 0;
            indeg[i] = 0;
        }
    }

    return 0;
}
