package imp;

//On codechef
//There should be no package while submitting and class should be like this.
import java.io.*;
import java.math.*;
import java.util.*;

class sol
{
	public static void main(String args[] ) throws Exception
	{
	   	
	   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  // Fast input
	   PrintWriter w = new PrintWriter(System.out);   // Fast output

       int i, j, T, N, M;
       BigDecimal p[][] = new BigDecimal[15][100010], q[] = new BigDecimal[15], ans1, ans2;

	   T = ip( br.readLine() );
	   while( (T--)>0 )
	   {
	   	   ans1 = BigDecimal.ONE;
	   	   ans2 = BigDecimal.ZERO;
         
           StringTokenizer st1 = new StringTokenizer( br.readLine() );
           N = ip( st1.nextToken() );
           M = ip( st1.nextToken() );

           for(i=0; i<N; i++)
           {
           	   StringTokenizer st2 = new StringTokenizer( br.readLine() );
           	   for(j=0; j<M; j++)
           	   {
                  p[i][j] = new BigDecimal( st2.nextToken() );
           	   }	
           	   q[i] = BigDecimal.ONE;
           }

           for(i=0; i<N; i++)
           {
           	   for(j=0; j<M; j++)
           	   {
           	   	  if( i==0 )
           	   	  {
                      ans1 = ans1.multiply( p[i][j] );                         
           	   	  }	
                  q[i] = q[i].multiply( p[i][j] );
           	   }

           	   ans2 = ans2.add( q[i] );
           }

           if( ans2.compareTo( BigDecimal.ZERO ) == 0 )  // Both value are equal
           {
       	       w.println( "0.000000" );	
           }	
           else
           {
           	   ans1 = ans1.divide(ans2, 6, BigDecimal.ROUND_HALF_UP);
           	   w.println( ans1 );
           }	                                                          
	   }
	   w.close();
	}

   	public static int ip(String s)
   	{
		return Integer.parseInt(s);
	}
}