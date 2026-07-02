/*
Author : deepak2015
Plagiarism is bad.
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

bool TT[8010][8010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll i, j, T, N, M, ppll;
    string st1, st2;

    cin >> T;
    rep(ppll, 1, T)
    {
       mset(TT, 0);
       cin >> st1 >> st2;

       string stri1 = "", stri2 = "";

       rep(i, 0, (int)st1.length()-1)
       {
           if( st1[i]!='*' )
           {
               stri1.pb( st1[i] );
           }
           else
           {
               stri1.pb( '_' );
               stri1.pb( '_' );
               stri1.pb( '_' );
               stri1.pb( '_' );
           }
       }
       rep(i, 0, (int)st2.length()-1)
       {
           if( st2[i]!='*' )
           {
               stri2.pb( st2[i] );
           }
           else
           {
               stri2.pb( '_' );
               stri2.pb( '_' );
               stri2.pb( '_' );
               stri2.pb( '_' );
           }
       }

       N = stri1.length();
       M = stri2.length();

       stri1 = "#" + stri1;
       stri2 = "#" + stri2;

       TT[0][0] = 1;
       rep(i, 1, (int)stri1.length()-1)
       {
           if( stri1[i]=='_' )
           {
              TT[0][i] = 1;
           }
           else
           {
               break;
           }
       }
       rep(i, 1, (int)stri2.length()-1)
       {
           if( stri2[i]=='_' )
           {
              TT[i][0] = 1;
           }
           else
           {
               break;
           }
       }


       rep(i, 1, (int)stri2.length()-1)
       {
           rep(j, 1, (int)stri1.length()-1)
           {
               if( stri1[j]==stri2[i] && stri1[j]=='_' )
               {
                   TT[i][j] = ( TT[i-1][j-1] | TT[i-1][j] | TT[i][j-1] );  // Both not included, either of one not included
               }
               else if( stri1[j]==stri2[i] )
               {
                   TT[i][j] = TT[i-1][j-1];   // check if prev when both not included is true
               }
               else if( stri1[j]=='_' )
               {
                   TT[i][j] = (TT[i-1][j-1] | TT[i][j-1]);  // Either _ matches with character or _ skipped
               }
               else if( stri2[i]=='_' )
               {
                   TT[i][j] = (TT[i-1][j-1] | TT[i-1][j]);  // Either _ matches with character or _ skipped
               }
           }
       }


       if( TT[M][N] )
       {
           cout << "Case #" << ppll << ": " << "TRUE" << endl;
       }
       else
       {
           cout << "Case #" << ppll << ": " << "FALSE" << endl;
       }
    }

    return 0;
}

