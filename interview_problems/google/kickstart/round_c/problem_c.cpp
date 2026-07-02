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
You can do something like this and then operate on vgvg
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
// Never use int or long array in function, always go for bool( as it is not global memory ). Also set.begin() and set.end() is constant in complexity O(1).

ll dp[60][60][60], Q, S[4];
string st[4], target;
ll func( ll ind, ll f1, ll f2 )
{
    if( ind==(Q+1) && f1==S[1] && f2==S[2] )
    {
        return 0;
    }
    if( ind==(Q+1) )
    {
        return INT_MIN;
    }
    if( dp[ind][f1][f2]!=-1 )
    {
        return dp[ind][f1][f2];
    }

    if( f1==S[1] && f2==S[2] )
    {
        if( st[1][ind]==st[2][ind] )
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2);
            }
            else
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2)+1;
            }
        }
        else
        {
            dp[ind][f1][f2] = func(ind+1, f1, f2);
        }
    }
    else if( f1==S[1] )
    {
        if( st[1][ind]==st[2][ind] )
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2);
            }
            else
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2)+1;
            }
        }
        else
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2+1);
            }
            else
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2+1)+1;
            }
        }
    }
    else if( f2==S[2] )
    {
        if( st[1][ind]==st[2][ind] )
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2);
            }
            else
            {
               dp[ind][f1][f2] = func(ind+1, f1, f2)+1;
            }
        }
        else
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = func(ind+1, f1+1, f2)+1;
            }
            else
            {
               dp[ind][f1][f2] = func(ind+1, f1+1, f2);
            }
        }
    }
    else
    {
        if( st[1][ind]==st[2][ind] )
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = max( func(ind+1, f1+1, f2+1)+1, func(ind+1, f1, f2) );
               //trace1("yo")
            }
            else
            {
               dp[ind][f1][f2] = max( func(ind+1, f1+1, f2+1), func(ind+1, f1, f2)+1 );
            }
        }
        else
        {
            if( st[1][ind]==target[ind] )
            {
               dp[ind][f1][f2] = max( func(ind+1, f1+1, f2)+1, func(ind+1, f1, f2+1) );
               //trace1("yo2")
            }
            else
            {
               dp[ind][f1][f2] = max( func(ind+1, f1, f2+1)+1, func(ind+1, f1+1, f2) );
            }
        }
    }

    //trace6(ind, f1, f2, dp[ind][f1][f2], f1, f2)
    return dp[ind][f1][f2];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, i, j, T, ppll;

    cin >> T;
    rep(ppll, 1, T)
    {
       mset(dp, -1);

       cin >> N >> Q;
       rep(i, 1, N)
       {
           cin >> st[i];
           st[i] = "#" + st[i];
       }
       cin >> target;
       target = "#" + target;

       rep(i, 1, N)
       {
           cin >> S[i];
       }

       if( N==1 )
       {
           ll same = 0;
           rep(i, 1, Q)
           {
               if( st[1][i]==target[i] )
               {
                   same++;
               }
           }

           ll opop = min(same, S[1]), opop2 = Q;
           if( same<S[1] )
           {
               S[1] -= same;   // not same and correct for 1
               opop2 -= same;  // not same

               opop2 -= S[1];
               opop += opop2;

               cout << "Case #" << ppll << ": " << opop << endl;
           }
           else
           {
               opop2 -= same;  // not same
               opop += opop2;

               cout << "Case #" << ppll << ": " << opop << endl;
           }
       }
       else
       {
           cout << "Case #" << ppll << ": " << func(1, 0, 0) << endl;
       }
    }

    return 0;
}
