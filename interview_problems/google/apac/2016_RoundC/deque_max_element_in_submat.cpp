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

    return (res%MOD);
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
    if( a==1 )
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
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// Always use double and never float.
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
// For Directed Acyclic Graph, DFS without marking visited vertices could lead to TLE( exponential solution ).

ll mat[3010][3010], A[3010], B[3010], mat2[3010][3010];
vector< ll > vc[3010];
deque< ll > dq[3010], dq2[3010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K, C, X, i, j, k, T, res, ppll;
    string st;

    cin >> T;
    rep(ppll, 1, T)
    {
       res = 0;
       rep(i, 0, 3002)
       {
           dq[i].clear();
           dq2[i].clear();
           vc[i].clear();
       }
       cin >> N >> K >> C >> X;
       rep(i, 1, N)
       {
           cin >> A[i];
       }
       rep(i, 1, N)
       {
           cin >> B[i];
       }
       rep(j, 1, N)
       {
           rep(k, 1, N)
           {
             mat[j][k] = ( ( A[j]*j ) + ( B[k]*k ) + C )%X;
           }
       }
       // Front has the maximum and back has the minimum, in sorted order.
       rep(i, 1, N)
       {
           rep(j, 1, K)
           {
               while( !dq[i].empty() && mat[i][j]>=mat[i][ dq[i].back() ] )
               {
                   dq[i].pop_back();
               }
               dq[i].pb( j );
           }
       }
       rep(i, 1, N)
       {
           rep(j, K+1, N)
           {
               vc[i].pb( mat[i][ dq[i].front() ] );
               while( !dq[i].empty() && dq[i].front()<=(j-K)  )
               {
                  dq[i].pop_front();
               }
               while( !dq[i].empty() && mat[i][j]>=mat[i][ dq[i].back() ]  )
               {
                  dq[i].pop_back();
               }
               dq[i].pb( j );
           }
           vc[i].pb( mat[i][ dq[i].front() ] );
       }

       //trace1(vc[1].size())

       // Transpose
       rep(i, 1, N)
       {
           rep(j, 0, (int)vc[i].size()-1)
           {
               mat2[j+1][i] = vc[i][j];
           }
       }

       // Front has the maximum and back has the minimum, in sorted order.
       rep(i, 1, N-K+1)
       {
           rep(j, 1, K)
           {
               while( !dq2[i].empty() && mat2[i][j]>=mat2[i][ dq2[i].back() ] )
               {
                   dq2[i].pop_back();
               }
               dq2[i].pb( j );
           }
       }
       rep(i, 1, N-K+1)
       {
           rep(j, K+1, N)
           {
               res += mat2[i][ dq2[i].front() ];
               while( !dq2[i].empty() && dq2[i].front()<=(j-K)  )
               {
                  dq2[i].pop_front();
               }
               while( !dq2[i].empty() && mat2[i][j]>=mat2[i][ dq2[i].back() ]  )
               {
                  dq2[i].pop_back();
               }
               dq2[i].pb( j );
           }
           res += mat2[i][ dq2[i].front() ];
           //trace2(ppll, res)
       }

       cout << "Case #" << ppll << ": " << res << endl;
    }

    return 0;
}
