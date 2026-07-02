#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)
#define endl "\n"
#define pb push_back
#define all(c) c.begin(),c.end()

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define tr(c,it) for(auto it=c.begin();it!=c.end();++it)
#define ll long long
#define mid(a,b) ((a)+((b-a)/2))
int min(int a, int b)
{
    if( a<b )
        return a;
    return b;
}
int max(int a, int b)
{
    if( a>b )
        return a;
    return b;
}
#define DEBUG
// debugging
#ifdef DEBUG
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define trace7(a, b, c, d, e, f, g)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << " | " << #g << " : " << g << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#define trace7(a, b, c, d, e, f, g)
#endif

vector< pair< int, int > > vc;
int qtree1[20010], arr[5010], arr2[5010], qtree2[20010], ans;
map< int, int > ma, ma2;
stack< int > stac[110];
void constree(int idx, int start, int en)
{
        if(start == en)
        {
                qtree1[idx] = arr2[ start ];
        }
        else
        {
                int m = mid(start, en);
                constree( 2*idx, start, m );
                constree( 2*idx + 1, m + 1, en );
                qtree1[idx] = min( qtree1[2*idx], qtree1[(2*idx) + 1] );
        }
}
void constree2(int idx, int start, int en)
{
        if(start == en)
        {
                qtree2[idx] = arr2[start];
        }
        else
        {
                int m = mid(start, en);
                constree2( 2*idx, start, m );
                constree2( 2*idx + 1, m + 1, en );
                qtree2[idx] =  max( qtree2[2*idx], qtree2[2*idx + 1] );
        }
}
void update1(int idx, int start, int en, int id, int x)
{
        if(start == en && start == id)
        {
                qtree1[idx] = x;
        }
        else if(id > en || id < start)
        {
                return;
        }
        else
        {
                int m = mid(start, en);
                update1( 2*idx, start, m, id, x);
                update1( 2*idx+1, m+1, en, id, x);
                qtree1[idx] = min( qtree1[2*idx], qtree1[(2*idx) + 1] );
        }
}
void update2(int idx, int start, int en, int id, int x)
{
        if(start == en && start == id)
        {
                qtree2[idx] = x;
        }
        else if(id > en || id < start)
        {
                return ;
        }
        else
        {
                int m = mid(start, en);
                update2( 2*idx, start, m, id, x);
                update2( 2*idx+1, m+1, en, id, x);
                qtree2[idx] =  max(qtree2[2*idx], qtree2[2*idx+1]);
        }
}
int query11(int idx,int start, int en, int b, int e)
{
        if(b > en || e < start)
        {
                return INT_MAX;   // Return is 0 as it won't affect the sum. In maxtree return is INT_MIN, in mintree return is INT_MAX : Therefore these also don't affect the respective trees.
        }
        else if(start >= b && en <= e)
        {
                return qtree1[idx];
        }
        else
        {
                int m = mid(start, en);
                int q1 = query11( 2*idx, start, m, b, e);
                int q2 = query11( 2*idx + 1, m + 1, en, b, e);
                return min(q1, q2);
        }
}
int query22(int idx,int start, int en, int b, int e)
{
        if(b > en || e < start)
        {
                return INT_MIN;   // Return is 0 as it won't affect the sum. In maxtree return is INT_MIN, in mintree return is INT_MAX : Therefore these also don't affect the respective trees.
        }
        else if(start >= b && en <= e)
        {
                return qtree2[ idx ];
        }
        else
        {
                int m = mid(start, en);
                int q1 = query22( 2*idx, start, m, b, e);
                int q2 = query22( 2*idx + 1, m + 1, en, b, e);
                return max(q1, q2);
        }
}

int main()
{
        #ifndef  ONLINE_JUDGE
            freopen("input.txt","r",stdin);
        #endif

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int i, N, M, ans1, ans2, iy;

        cin >> N >> M;
        rep(i, 0, N-1)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
            ma2[ arr[i] ] += 1;
            stac[ arr[i] ].push( i );
        }
        sort(arr, arr+N);

        constree(1, 0, N-1);
        constree2(1, 0, N-1);
        rep(i, 0, N-1)
        {
                ans1 = query11(1, 0, N-1, 0, N-1); // min
                ans2 = query22(1, 0, N-1, 0, N-1); // max
                if( ans1!=arr[i] && ma2[ans1] )
                {
                   ans++;
                   vc.pb( mp( arr[i], ans1 ) );
                   ma2[ans1]--;
                   iy = stac[ans1].top();
                   stac[ans1].pop();
                   update1(1, 0, N-1, iy, INT_MAX);
                   update2(1, 0, N-1, iy, INT_MIN);
                }
                else if( ans2!=arr[i] && ma2[ans2] )
                {
                   ans++;
                   vc.pb( mp( arr[i], ans2 ) );
                   ma2[ans2]--;
                   iy = stac[ans2].top();
                   stac[ans2].pop();
                   update2(1, 0, N-1, iy, INT_MIN);
                   update1(1, 0, N-1, iy, INT_MAX);
                }
                else if( ma2[ ans1 ] )
                {
                   vc.pb( mp( arr[i], ans1 ) );
                   ma2[ans1]--;
                   iy = stac[ans1].top();
                   stac[ans1].pop();
                   update2(1, 0, N-1, iy, INT_MIN);
                   update1(1, 0, N-1, iy, INT_MAX);
                }
                else
                {
                   vc.pb( mp( arr[i], ans2 ) );
                   ma2[ans2]--;
                   iy = stac[ans2].top();
                   stac[ans2].pop();
                   update2(1, 0, N-1, iy, INT_MIN);
                   update1(1, 0, N-1, iy, INT_MAX);
                }
                //trace7(iy, arr[i], ans1, ans2, ma2[ans1], ma2[ans2], qtree2[1])
        }
        cout << ans << endl;
        rep(i, 0, (int)vc.size()-1)
        {
          cout << vc[i].f << " " << vc[i].s << endl;
        }

        return 0;
}
