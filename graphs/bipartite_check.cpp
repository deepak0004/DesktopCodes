#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, s, e) for(i=s; i<=e; i++)
#define pb push_back

vector< ll > adj[100010];
ll col[100010], visited[100010], c0, c1, cnt, arr[100010];

void dfs(ll src, ll par)
{
    visited[src] = 1;
    cnt++;
    ll h = adj[src].size(), i, xx;
    rep(i, 0, h-1)
    {
        xx = adj[src][i];
        if( ( visited[xx]==1 ) || ( xx==par ) )
        {
            continue;
        }
        dfs(xx, src);
    }
}

ll comb2( ll N )
{
    return ( N*(N-1) )/2;
}
ll comb3( ll N )
{
    return ( N*(N-1)*(N-2) )/6;
}

bool bipartile( ll src )
{
    ll i, xx, u, h;
    col[src] = 1;
    queue< ll > qu;
    qu.push(src);
    c1++;

    while( !qu.empty() )
    {
        u = qu.front();
        qu.pop();

        h = adj[u].size();
        rep(i, 0, h-1)
        {
            xx = adj[u][i];
            if( col[xx]==-1 )
            {
           //     cout << xx << endl;
                col[xx] = 1-col[u];
                qu.push( xx );
                if( col[xx]==1 )
                {
                    c1++;
                }
                else
                {
                    c0++;
                }
            }
            else if( col[xx]==col[u] )
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
   #ifndef  ONLINE_JUDGE
        freopen("input.txt","r",stdin);
   #endif

   ios_base::sync_with_stdio(false);
   cin.tie(0);

   ll N, M, i, j, A, B, maxx = INT_MIN;

   cin >> N >> M;
   rep(i, 0, M-1)
   {
       cin >> A >> B;
       --A;
       --B;
       adj[A].pb( B );
       adj[B].pb( A );
   }

   memset(col, -1, sizeof(col));
   rep(i, 0, N-1)
   {
       if( col[i]==-1 )
       {
           if( bipartile(i)==0 )
           {
               cout << "0 1";
               return 0;
           }
       }
   }

   rep(i,0, N-1)
   {
       if( visited[i]==0 )
       {
           cnt = 0;
           dfs(i, -1);
           arr[cnt]++;
           maxx = max( maxx, cnt);
       }
   }

   if( maxx==2 )
   {
       cout << "2 ";
       ll ans = ( comb2(arr[2]) * 4 ) + ( arr[2] * ( N-(2*arr[2]) ) );
       cout << ans;
       return 0;
   }
   if( maxx==1 )
   {
       cout << "3 ";
       cout << comb3(N);
       return 0;
   }

   cout << "1 ";
   ll way = 0;
   memset(col, -1, sizeof(col));
   rep(i, 0, N-1)
   {
       if( col[i]==-1 )
       {
           c0 = 0;
           c1 = 0;
           bipartile(i);
      //     cout << c0 << " " << c1 << " " << i << endl;
           way += comb2(c0) + comb2(c1);
       }
   }
   cout << way;

   return 0;
}
