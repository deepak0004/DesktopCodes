/*
Author : deepak2015
Plagiarism is bad.
*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define epsilon 0.000000000001
#define PI 3.1415926535897932
#define I_MAX 92203685477580799
#define I_MIN -92203685477580799
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

// scanf and printf
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")

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
ll pow_2(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a);
        a = (a * a);
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
string con_ll_to_str( int a )
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
       numb += ( pow_2(10, j) * ( st[i] - '0' ) );
       j++;
    }

    return numb;
}
ll baseno_to_decimal( string st, ll basee )
{
    ll i = 0, j, anss = 0;
    rrep(j, (int)st.length()-1, 0)
    {
        anss += ( st[j] - '0' ) * pow_2( basee, i );
        i++;
    }

    return anss;
}
string decimal_to_string( ll num, ll basee )
{
    ll i = 0, j, opop;
    string anss = "";
    vector< string > stri;
    stri.pb("0"); stri.pb("1"); stri.pb("2"); stri.pb("3");
    stri.pb("4"); stri.pb("5"); stri.pb("6"); stri.pb("7");
    stri.pb("8"); stri.pb("9"); stri.pb("A"); stri.pb("B");
    stri.pb("C"); stri.pb("D"); stri.pb("E"); stri.pb("F");
    while( num )
    {
        opop = num%basee;
        anss += stri[opop];
        num /= basee;
    }
    reverse( all(anss) );

    return anss;
}
// map : log2(N) find, count, etc
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

ll heig[1010][1010];
bool vis[1010][1010];
vector< pair<ll, ll> > vc2;
vector< vector< pair<ll, ll> >  > vc[1010];
void dfs( ll x, ll y, ll he, ll R, ll C )
{
    if( x<1 || y<1 || x>R || y>C )
        return;

    if( vis[x][y] )
    {
        return;
    }
    if( heig[x][y]==he )
    {
       vc2.pb( mp(x, y) );
    }
    else
    {
       return;
    }
    vis[x][y] = 1;
    dfs(x-1, y, he, R, C);
    dfs(x+1, y, he, R, C);
    dfs(x, y-1, he, R, C);
    dfs(x, y+1, he, R, C);
}
ll check( ll x, ll y, ll R, ll C, ll he )
{
    if( x<1 || y<1 || x>R || y>C )
        return 0;

    return heig[x][y];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, i, j, k, T, ppll, R, C;

    cin >> T;
    rep(ppll, 1, T)
    {
       ll mi = INT_MAX, ma = INT_MIN, anss = 0, pp;
       mset(heig, 0);
       mset(vis, 0);
       vc2.clear();
       rep(i, 1, 1000)
         vc[i].clear();

       cin >> R >> C;
       rep(i, 1, R)
       {
          rep(j, 1, C)
          {
              cin >> heig[i][j];
              mi = min(mi, heig[i][j]);
              ma = max(ma, heig[i][j]);
          }
       }
       rep(i, mi, ma)
       {
           rep(j, 1, R)
           {
               rep(k, 1, C)
               {
                   vc2.clear();
                   if( heig[j][k]==i && !vis[j][k] )
                   {
                       dfs(j, k, i, R, C);
                       if( vc2.size() )
                       {
                           vc[i].pb(vc2);
                       }
                   }
               }
           }
       }
//       rep(i, mi, ma)
//       {
//           cout << i << endl;
//           //trace2(vc[i].size(), i)
//           rep(j, 0, (int)vc[i].size()-1)
//           {
//              rep(k, 0, (int)vc[i][j].size()-1)
//              {
//                  cout << vc[i][j][k].f << " " << vc[i][j][k].s << " ";
//              }
//              cout << endl;
//           }
//       }
       rep(i, mi, ma)
       {
           rep(j, 0, (int)vc[i].size()-1)
           {
              ll res = INT_MAX;
              rep(k, 0, (int)vc[i][j].size()-1)
              {
                   ll opop1 = check( vc[i][j][k].f-1, vc[i][j][k].s, R, C, i );
                   ll opop2 = check( vc[i][j][k].f+1, vc[i][j][k].s, R, C, i );
                   ll opop3 = check( vc[i][j][k].f, vc[i][j][k].s-1, R, C, i );
                   ll opop4 = check( vc[i][j][k].f, vc[i][j][k].s+1, R, C, i );
                   if( opop1!=i )
                     res = min(res, opop1);
                   if( opop2!=i )
                     res = min(res, opop2);
                   if( opop3!=i )
                     res = min(res, opop3);
                   if( opop4!=i )
                     res = min(res, opop4);
              }
              if( res>i && res!=INT_MAX )
              {
                   vc2.clear();
                   rep(k, 0, (int)vc[i][j].size()-1)
                   {
                       anss += (res - heig[ vc[i][j][k].f ][ vc[i][j][k].s ]);
                       heig[ vc[i][j][k].f ][ vc[i][j][k].s ] = res;
                       vc2.pb( mp( vc[i][j][k].f, vc[i][j][k].s ) );
                   }
                   if( vc2.size() )
                   {
                       mset(vis, 0);
                       vc[res].clear();
                       rep(pp, 1, R)
                       {
                           rep(k, 1, C)
                           {
                               vc2.clear();
                               if( heig[pp][k]==res && !vis[pp][k] )
                               {
                                   dfs(pp, k, res, R, C);
                                   if( vc2.size() )
                                   {
                                       vc[res].pb(vc2);
                                   }
                               }
                           }
                       }
                   }
              }
           }
       }

       cout << "Case #" << ppll << ": " << anss << endl;
    }

    return 0;
}
