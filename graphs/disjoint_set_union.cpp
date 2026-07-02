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
    if( num==0 )
    {
        return "0";
    }
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

// rank is height
vector< pair<ll, ll> > subset;                     // parent, rank
string st[100010];
map< pair<ll, ll>, bool > oppo;
map< string, ll > poss;
map< ll, ll > opopii;

ll FIND_( ll i )
{
    if( subset[i].f!=i )
         subset[i].f = FIND_( subset[i].f );

    return subset[i].f;
}
ll UNION_( ll x, ll y )
{
    ll xpart = FIND_( x );
    ll ypart = FIND_( y );
    ll par;
    if( subset[xpart].s<subset[ypart].s )
    {
        par = ypart;
        subset[xpart].f = ypart;
    }
    else if( subset[xpart].s>subset[ypart].s )
    {
        par = xpart;
        subset[ypart].f = xpart;
    }
    else
    {
        par = xpart;
        subset[ypart].f = xpart;
        subset[xpart].s++;
    }

    return par;
}

int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, N, M, Q, T, XX, YY;
    string X, Y;

    cin >> N >> M >> Q;

    rep(i, 0, N-1)
    {
        cin >> st[i];
        poss[ st[i] ] = i;
        subset.pb( mp(i, 0) );
        opopii[i] = -1;
    }
    while( M-- )
    {
        cin >> T >> X >> Y;
        XX = poss[X];
        YY = poss[Y];

        ll x = FIND_( XX );
        ll y = FIND_( YY );

        if( T==1 )
        {
           if( x==y )
           {
               cout << "YES" << endl;
           }
           else if( !oppo[ mp(x, y) ] || !oppo[ mp(y, x) ] )
           {
               ll paa = UNION_(x, y);

               if( opopii[ x ]!=-1 && opopii[ y ]!=-1 )
               {
                  ll pa1 = UNION_(opopii[ y ], opopii[ x ]);

                  oppo[ mp(pa1, paa) ] = 1;
                  oppo[ mp(paa, pa1) ] = 1;
                  opopii[ paa ] = pa1;
                  opopii[ pa1 ] = paa;
               }
               else if( opopii[ x ]!=-1 )
               {
                  ll pa1 = opopii[ x ];

                  oppo[ mp(pa1, paa) ] = 1;
                  oppo[ mp(paa, pa1) ] = 1;
                  opopii[ pa1 ] = paa;
                  opopii[ paa ] = pa1;
               }
               else if( opopii[ y ]!=-1 )
               {
                  ll pa1 = opopii[ y ];

                  oppo[ mp(pa1, paa) ] = 1;
                  oppo[ mp(paa, pa1) ] = 1;
                  opopii[ pa1 ] = paa;
                  opopii[ paa ] = pa1;
               }

               cout << "YES" << endl;
           }
           else
           {
               cout << "NO" << endl;
           }
        }
        else
        {
           if( x==y )
           {
               cout << "NO" << endl;
           }
           else
           {
               if( opopii[ x ]!=-1 && opopii[ y ]!=-1 )
               {
                  ll pa1 = UNION_(y, opopii[ x ]);
                  ll pa2 = UNION_(x, opopii[ y ]);

                  oppo[ mp(pa1, pa2) ] = 1;
                  oppo[ mp(pa2, pa1) ] = 1;
                  opopii[ pa1 ] = pa2;
                  opopii[ pa2 ] = pa1;
               }
               else if( opopii[ x ]!=-1 )
               {
                  ll pa1 = UNION_(y, opopii[ x ]);

                  oppo[ mp(pa1, x) ] = 1;
                  oppo[ mp(x, pa1) ] = 1;
                  opopii[ pa1 ] = x;
                  opopii[ x ] = pa1;
               }
               else if( opopii[ y ]!=-1 )
               {
                  ll pa1 = UNION_(x, opopii[ y ]);

                  oppo[ mp(pa1, y) ] = 1;
                  oppo[ mp(y, pa1) ] = 1;
                  opopii[ pa1 ] = y;
                  opopii[ y ] = pa1;
               }
               else
               {
                  oppo[ mp(x, y) ] = 1;
                  oppo[ mp(y, x) ] = 1;
                  opopii[ x ] = y;
                  opopii[ y ] = x;
               }

               cout << "YES" << endl;
           }
        }
    }
    while( Q-- )
    {
        cin >> X >> Y;

        XX = poss[X];
        YY = poss[Y];

        ll x = FIND_( XX );
        ll y = FIND_( YY );

        if( x==y )
        {
            cout << "1" << endl;
        }
        else if( oppo[ mp(x, y) ] )
        {
            cout << "2" << endl;
        }
        else
        {
            cout << "3" << endl;
        }
    }

    return 0;
}
