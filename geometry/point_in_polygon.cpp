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

vector< pair<ll, ll> > vc;
bool insidepolygon( ll i, ll j, pair<float, float> test )
{
   // following statement checks if testPoint.Y is below Y-coord of i-th vertex
   bool belowLowY = (vc[i].s>test.s);
   // following statement checks if testPoint.Y is below Y-coord of i+1-th vertex
   bool belowHighY = (vc[j].s>test.s);
   /*
   following statement is true if testPoint.Y satisfies either (only one is possible)
        -->(i).Y < testPoint.Y < (i+1).Y        OR
        -->(i).Y > testPoint.Y > (i+1).Y
   Both of the conditions indicate that a point is located within the edges of the Y-th coordinate
   of the (i)-th and the (i+1)- th vertices of the polygon. If neither of the above
   conditions is satisfied, then it is assured that a semi-infinite horizontal line draw
   to the right from the testpoint will NOT cross the line that connects vertices i and i+1
   of the polygon
   */
   bool withinYsEdges = (belowLowY != belowHighY);

   if( withinYsEdges )
   {
     // this is the slope of the line that connects vertices i and i+1 of the polygon
     float slopeOfLine = ( (float)( vc[j].f-vc[i].f ) ) / ( vc[j].s-vc[i].s );
     // this looks up the x-coord of a point lying on the above line, given its y-coord
     float pointOnLine = ( slopeOfLine * ( test.s-vc[i].s ) ) + vc[i].f;
     //checks to see if x-coord of testPoint is smaller than the point on the line with the same y-coord
     bool isLeftToLine = test.f < pointOnLine;
     if(isLeftToLine)
     {
        return 1;
     }
   }

   return 0;
    /*
    j = i+1
    (vertexY_j - vertexY_i) / (vertexX_j - vertexX-i) = ( testY - vertexY_i ) / ( unknownX - vertexX_i )
    */
}
int main()
{
    #ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, i, j, A, B, ans = 0;
    float fir, sec;
    string st1;

    cin >> N;
    rep(i, 1, N+1)
    {
        cin >> A >> B;
        vc.pb( mp(A, B) );
    }
    rep(i, 1, N)
    {
       bool locatedInPolygon = 0;
       pair< float, float > test;  // checking point
       if( vc[i].f==vc[i-1].f )
       {
           fir = vc[i].f;
           if( vc[i].s>vc[i-1].s )
              sec = vc[i].s+0.2;
           else
              sec = vc[i].s-0.2;
       }
       else
       {
           sec = vc[i].s;
           if( vc[i].f>vc[i-1].f )
              fir = vc[i].f+0.2;
           else
              fir = vc[i].f-0.2;
       }

       test = mp( fir, sec );
       rep(j, 0, N-1)
       {
          if( insidepolygon( j, j+1, test ) )
          {
             //this statement changes true to false (and vice-versa)
             locatedInPolygon = !locatedInPolygon;
          }
       }

       if( locatedInPolygon )
       {
           ans++;
       }
    }
    cout << ans;

    return 0;
}
