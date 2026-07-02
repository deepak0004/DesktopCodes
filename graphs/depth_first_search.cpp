
 /*
Author : deepak2015
I am a coder.
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

ll vis[1004][1004], kk = 1, N, M, ans, dp[1000004];
string st[1100], st2[1100];

void dfs( ll X, ll Y )
{
    if( X<=0 || Y>M || X>N || Y<=0 )
    {
        return;
    }
    if( st[X][Y]=='*' )
    {
        return;
    }
    if( vis[X][Y] )
    {
        return;
    }
    vis[X][Y] = kk;
    dfs( X-1, Y );
    dfs( X+1, Y );
    dfs( X, Y-1 );
    dfs( X, Y+1 );

    return;
}
void func( ll i, ll j )
{
   set< ll > se;
   se.insert( vis[i][j+1] );
   se.insert( vis[i][j-1] );
   se.insert( vis[i-1][j] );
   se.insert( vis[i+1][j] );

   tr(se, it)
   {
       if( *it != 0 )
       {
           ans += dp[ *it ];
       }
   }
   ans++;
}
int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j;

    cin >> N >> M;
    rep(i, 1, N)
    {
        cin >> st[i];
        st[i] = "0" + st[i];
        st2[i] = st[i];
    }
    rep(i, 1, N)
    {
        rep(j, 1, M)
        {
           if( st[i][j]=='.' && !vis[i][j] )
           {
             kk++;
             dfs(i, j);
           }
        }
    }
    rep(i, 1, N)
    {
        rep(j, 1, M)
        {
           dp[ vis[i][j] ]++;
        }
    }
//    rep(i, 1, 5)
//     cout << dp[i] << " ";
//    cout << endl;
    rep(i, 1, N)
    {
        rep(j, 1, M)
        {
           if( st[i][j]=='*' )
           {
               ans = 0;
               func( i, j );
               if( ans>=10 )
                ans %= 10;
               char c = ( ans + '0' );
               st2[i][j] = c;
           }
        }
    }
    rep(i, 1, N)
    {
        cout << st2[i].substr(1) << endl;
    }

    return 0;
}
