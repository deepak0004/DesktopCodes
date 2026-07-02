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
    for(ll i=3; (i*i)<=a; i+=2)
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
string con_ll_to_str( ll a )
{
    stringstream mystr;
    mystr << a;
    return mystr.str();
}
ll con_str_to_ll( string st )
{
    ll numb = 0;
    ll len = st.size(), i, j = 0;
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
// For multiset to remove one element, which is not unique, it deletes all. So, u can do like this:
/*
auto itr = mse.find(arr[i]);
if( itr!=mse.end() )
    mse.erase(itr);
*/
// Always store pointer in a variable, never use auto it itself, because it may happen u delete it once and then again use it causing runtime error.
/*
U can do something like this and then operate on vgvg
 pair<ll, ll> vgvg = mp(it->f, it->s);
*/
// In comparison of a  function of sort, never use equal to, it causes runtime error. comp(a, a) must return false.
/*
Use this instead:
bool comp( pair<ll ,ll> pa1, pair<ll ,ll> pa2 )
{
    return (pa1.f-pa1.s)<(pa2.f-pa2.s);
}
*/
// For find in array or any function, first check if it is of non-zero size or not.
// For codechef too 10^8 computation( still here or there check )

ll mat[60][60], star[60], R[60];
bool comp( pair< pair<ll, ll>, ll > pa1, pair< pair<ll, ll>, ll > pa2 )
{
    return pa1.f.s<pa2.f.s;
}
pair<ll, ll> bsearch( ll val, ll ind )
{
    ll lo = 1, hi = 1e6, mid, beg = -1, endd = -1;

    while( lo<=hi )
    {
        mid = (lo + hi) / 2;
        double lower = (mid*R[ind]*0.9), higher = (mid*R[ind]*1.1);
        if( lower<=val && higher>=val )
        {
            beg = mid;
            hi = mid-1;
        }
        else if( lower<val )
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }

    lo = 1;
    hi = 1e6;
    while( lo<=hi )
    {
        mid = (lo + hi) / 2;
        double lower = (mid*R[ind]*0.9), higher = (mid*R[ind]*1.1);
        if( lower<=val && higher>=val )
        {
            endd = mid;
            lo = mid+1;
        }
        else if( lower<val )
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }

    return mp(beg, endd);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll T, N, P, i, j, fres, ppll;
    string st;

    cin >> T;
    rep(ppll, 1, T)
    {
        fres = 0;
        mset(mat, 0);
        mset(star, 0);
        mset(R, 0);

        cin >> N >> P;
        rep(i, 1, N)
        {
            cin >> R[i];
        }
        rep(i, 1, N)
        {
            rep(j, 1, P)
            {
                cin >> mat[i][j];
            }
            sort(mat[i]+1, mat[i]+P+1);
        }
        rep(i, 1, N)
        {
            star[i] = 1;
        }
        while(1)
        {
            vector< pair< pair<ll, ll>, ll > > vc;

            bool flag = 0;
            rep(i, 1, N)
            {
                if( star[i]>P )
                {
                    flag = 1;
                    break;
                }
            }
            if( flag )
            {
                break;
            }

            rep(i, 1, N)
            {
                ll val = mat[i][star[i]];
                pair<ll, ll> paa = bsearch( val, i );
                vc.pb( mp(paa, i) );
            }

            sort( all(vc), comp );
            ll o1, coun = 0;
            rep(i, 0, (int)vc.size()-1)
            {
                if( !i )
                {
                   o1 = vc[i].f.s;
                }
                else
                {
                   if( vc[i].f.f<=o1 )
                   {
                       coun++;
                   }
                }
            }
            //trace2(o1, coun)
            if( o1!=-1 && coun==(vc.size()-1) )
            {
                fres++;
                rep(i, 1, N)
                {
                    star[i]++;
                }
            }
            else
            {
                star[vc[0].s]++;
                //trace1(star[vc[0].s])
            }
        }

        cout << "Case #" << ppll << ": " << fres << endl;
    }

    return 0;
}
