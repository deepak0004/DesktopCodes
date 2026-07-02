#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mset(arr,x) memset(arr,x,sizeof(arr))
#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)

double dp[4010][4010];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, i, j, T, M, ppll;
    string st;

    cin >> T;
    rep(ppll, 1, T)
    {
       cin >> N >> M;
       rep(i, 1, N)
       {
           dp[i][0] = 1.0;
       }

       rep(i, 1, N)
       {
           rep(j, 1, i-1)
           {
               if( i!=j )
               {
                   dp[i][j] = ( dp[i-1][j] * ( ( (double)i )/(i+j) ) ) + ( dp[i][j-1] * ( (double)j/(i+j) ) );
               }
           }
       }

       cout << "Case #" << ppll << ": " << setprecision(12) << dp[N][M] << endl;

       rep(i, 0, N)
       {
          rep(j, 0, M)
          {
          	 dp[i][j] = 0.0;
          }
       }
    }

    return 0;
}
