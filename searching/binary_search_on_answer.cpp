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

ll arr[500100], N, K, su;
bool binary( ll mid )
{
    ll i, kk = 0;
    rep(i, 1, N)
    {
        kk += max( mid-arr[i], 0 );
    }

    if( kk<=K )
        return 1;

    return 0;
}
bool binary2( ll mid )
{
    ll i, kk = 0;
    rep(i, 1, N)
    {
        kk += max( arr[i]-mid, 0 );
    }

    if( kk<=K )
        return 1;

    return 0;
}
int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j, lo, hi, mid, max_val = I_MIN, ans1, ans2;
    string st;

    cin >> N >> K;
    rep(i, 1, N)
    {
        cin >> arr[i];
        su += arr[i];
        max_val = max( max_val, arr[i] );
    }

    lo = 1;
    hi = max_val;
    while( lo<=hi )
    {
        mid = ( lo + hi ) / 2;
        if( binary( mid ) )
        {
            ans1 = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    lo = 1;
    hi = max_val;
    while( lo<=hi )
    {
        mid = ( lo + hi ) / 2;
        if( binary2( mid ) )
        {
            ans2 = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if( ans2 <= ans1)
    {
        if( ( su % N ) != 0 )
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << ans2 - ans1;
    }

    return 0;
}
