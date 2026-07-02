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

int mat[30][30], mat2[30][30];
vector<ll> vc[30], vc2[30];
void func( int type, int star, int endd, int add_what, int N )
{
    int i, j, k;
    if( type==1 ) // left or right
    {
        rep(i, 1, N)
        {
            j = star;
            while( j!=endd )
            {
              if( mat[i][j] )
              {
                  vc[i].pb( mat[i][j] );
              }
              j += add_what;
            }
        }
    }
    else         // up or down
    {
        rep(i, 1, N)
        {
            j = star;
            while( j!=endd )
            {
              if( mat[j][i] )
              {
                  vc[i].pb( mat[j][i] );
              }
              j += add_what;
            }
        }
    }

    rep(i, 1, N)
    {
        rep(j, 0, (int)vc[i].size()-2)
        {
            if( vc[i][j]==vc[i][j+1] )
            {
               vc2[i].pb( 2*vc[i][j] );
               j += 1;
            }
            else
            {
               vc2[i].pb( vc[i][j] );
            }
        }
        if( j!=vc[i].size() )
        {
            vc2[i].pb( vc[i][j] );
        }
    }
//    rep(i, 1, N)
//    {
//        rep(j, 0, (int)vc[i].size()-1)
//        {
//            cout << vc[i][j] << " ";
//        }
//        cout << endl;
//    }

    if( type==1 )
    {
        rep(i, 1, N)
        {
            k = 0;
            j = star;
            while( (j!=endd) && (k<vc2[i].size()) )
            {
              mat2[i][j] = vc2[i][k];
              j += add_what;
              k++;
            }
        }
    }
    else
    {
        rep(i, 1, N)
        {
            k = 0;
            j = star;
            while( (j!=endd) && (k<vc2[i].size()) )
            {
              mat2[j][i] = vc2[i][k];
              j += add_what;
              k++;
            }
        }
    }
}
int main()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);

     ios_base::sync_with_stdio(false);
     cin.tie(0);

     int T, N, i, j, ppll;
     string st;

     cin >> T;
     rep(ppll, 1, T)
     {
         mset(mat, 0);
         mset(mat2, 0);
         rep(i, 0, 28)
         {
             vc[i].clear();
             vc2[i].clear();
         }

         cin >> N >> st;
         rep(i, 1, N)
         {
             rep(j, 1, N)
             {
                 cin >> mat[i][j];
             }
         }

         if( st=="right" )
         {
             func(1, N, 0, -1, N);
         }
         else if( st=="left" )
         {
             func(1, 1, N+1, 1, N);
         }
         else if( st=="up" )
         {
             func(2, 1, N+1, 1, N);
         }
         else
         {
             func(2, N, 0, -1, N);
         }

         cout << "Case #" << ppll << ":" << endl;
         rep(i, 1, N)
         {
             rep(j, 1, N)
             {
                 cout << mat2[i][j] << " ";
             }
             cout << endl;
         }
     }

     return 0;
}
