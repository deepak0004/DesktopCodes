#define all(st) st.begin(), st.end()
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define tr(c,it) for(auto it=c.begin();it!=c.end();++it)
#define trrev(c,it) for(auto it=c.rbegin();it!=c.rend();++it)
int pow_mod(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
bool isPrime(int a)
{
    for(int i=3; (i*i)<=a; i+=2)
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
string con_int_to_str( int a )
{
    stringstream mystr;
    mystr << a;
    return mystr.str();
}
int baseno_to_decimal( string st, int basee )   // 10 in base 10
{
    int i = 0, j, anss = 0;
    for(j=(int)st.length()-1; j>=0; j--)
    {
        anss += ( st[j] - '0' ) * pow_mod( basee, i );
        i++;
    }

    return anss;
}
string decimal_to_string( int num, int basee )
{
    int i = 0, j, opop;
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
/*
struct comp
{
    bool operator()( pair<int,int> n1, pair<int,int> n2 )
    {
        return n1.s > n2.s;
    }
}
priority_queue< pair<int, int>, vector< pair<int, int> >, comp > prqu;
struct nodee
{
   int val;
   nodee *lft, *rgt;
   nodee()
   {
       val = 0;
       lft = NULL;
       rgt = NULL;
   }
};
root->lft = new nodee;
(root->lft)->val = 2;
ro = 1;
co = 1;
while(1)
{
    if( (N+1-ro)<ro )
    {
        break;
    }

    rep(i, co, N+1-co)
    {
       cout << arr[ro][i] << " ";
    }
    rep(i, ro+1, N+1-ro-1)
    {
        cout << arr[i][N+1-co] << " ";
    }

    if( ro!=(N+1-ro) )
    {
        rrep(i, N+1-co, co)
        {
           cout << arr[N+1-ro][i] << " ";
        }
    }
    if( co!=(N+1-co) )
    {
        rrep(i, N+1-ro-1, ro+1)
        {
            cout << arr[i][co] << " ";
        }
    }
    ro++;
    co++;
}
void topo_sort( ll ind, ll par )
{
  ll i;
  vis[ ind ] = 1;
  rep(i, 0, (int)vc[ind].size()-1)
  {
      if( !vis[ vc[ind][i] ] )
      {
          topo_sort( vc[ind][i], ind );
      }
  }

  stac.push( ind );
  return;
}
struct node *lca( struct node *nod, int n1, int n2 )
{
    if( nod==NULL )
    {
        return NULL;
    }
    if( nod->data==n1 )
    {
        v1 = true;
        return nod;
    }
    if( nod->data==n2 )
    {
        v2 = true;
        return nod;
    }
    struct node *left = lca( nod->left, n1, n2 );
    struct node *right = lca( nod->right, n1, n2 );
    if( left!=NULL && right!=NULL )
    {
        return nod;
    }
    if( left==NULL )
        return right;
    return left;
}
bool fin( struct node *nod, int key )
{
    if( nod==NULL )
    {
        return false;
    }
    if( nod->data==key )
    {
        return true;
    }
    return fin( nod->left, key ) || fin( nod->right, key );
}
    int inte = (int)N;
    st = con_ll_to_str( inte );
    double dec = N - inte;
    double rem = dec;

    while(abs(rem)>epsilon)
    {
        rem *= 10.0;
        int integ = (int)rem;
        st2 += con_ll_to_str( integ%10 );
        rem = rem - (double)integ;
        trace1(rem)
    }
*/
