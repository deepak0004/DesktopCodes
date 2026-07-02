#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define epsilon 0.000000000001
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

int L[110][110];
int main()
{
    #ifndef  ONLINE_JUDGE
       freopen("input.txt","r",stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, c1;
    string st;

    cin >> st;
    rep(i, 0, (int)st.length()-1)
    {
       L[i][i] = 1;
    }
    /*
    L[ i ][ j ]
       |   |
       |   |
       |   index2
       |
     index1

     index1 to index2
    */
    rep(c1, 2, (int)st.length())
    {
        rep(i, 0, (int)st.length()-c1)
        {
            j =  i+c1-1;
            if( st[i]==st[j] && c1==2 )
            {
               L[i][j] = 2;
            }
            else if( st[i]==st[j] )
            {
                L[i][j] = L[i+1][j-1] + 2;
            }
            else
            {
                L[i][j] = max( L[i][j-1], L[i+1][j]);
            }
        }
    }
    cout << L[0][st.length()-1];

    return 0;
}
