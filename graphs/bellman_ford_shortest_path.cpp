#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,e) for(i=s;i<=e;i++)
#define endl "\n"
#define I_MAX 9223372038
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define pb push_back
#define mp make_pair
#define f first
#define s second

ll parent[500010], dist[500010], iteration;
vector< pair< pair<ll, ll>, ll > > edge;
bool bellman( ll src )
{
        ll i, h, opop;
        pair<ll, ll> xx;
        dist[src] = 0;

        while( iteration-- )
        {
            rep(i, 0, (ll)edge.size()-1)
            {
                    if( ( dist[ edge[i].f.f ] + edge[i].s ) < dist[ edge[i].f.s ] )
                    {
                        dist[ edge[i].f.s ] = ( dist[ edge[i].f.f ] + edge[i].s);
                        parent[ edge[i].f.s ] = edge[i].f.f;   // parent stores vertex from which it arrived
                    }
            }
        }

        rep(i, 0, (ll)edge.size()-1)
        {
                if( ( dist[ edge[i].f.f ] + edge[i].s ) < dist[ edge[i].f.s ] )
                {
                    dist[ edge[i].f.s ] = ( dist[ edge[i].f.f ] + edge[i].s);
                    parent[ edge[i].f.s ] = edge[i].f.f;   // parent stores vertex from which it arrived
                    return false;
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

        ll N, M, X, Y, W, j, i, T, src1, dst;

        cin >> T;
        while( T-- )
        {
            cin >> N >> M;
            iteration = N-1;
            rep(i, 1, N)
            {
                dist[i] =  I_MAX;
                parent[i] = 0;
            }
            edge.clear();

            rep(i, 1, M)
            {
                cin >> X >> Y >> W;
                edge.pb( mp( mp(X, Y), W) );
            }
            cin >> src1 >> dst;

            if( bellman( src1 ) )
            {
                if( dist[dst]==I_MAX )
                {
                    cout << "NO" << endl;
                }
                else
                {
                   cout << dist[dst] << endl;
                }
            }
            else
            {
                cout << "NO";
            }
        }

        return 0;

}

/*
adj[X].pb( mp(Y, W) );
              |  |
              |  |
           node  weight
*/
