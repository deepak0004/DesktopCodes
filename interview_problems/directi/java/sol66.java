package imp;

import java.io.*;
import java.math.*;
import java.util.*;
 
public class sol66
{
	public static void main( String args[] )
	{
	   Scanner mm = new Scanner( System.in );
	   int L[] = new int[ 100010 ], R[] = new int[ 100010 ], arr1[] = new int[ 100010 ], arr2[] = new int[ 100010 ], N, i, P;

	   N = mm.nextInt();
	   P = mm.nextInt();
       for(i=1; i<=N; i++)
       {	
    	   L[i] = mm.nextInt();
    	   R[i] = mm.nextInt();
    	   arr1[i] = R[i] - L[i] + 1;
    	   arr2[i] = ( R[i] / P ) - ( ( L[i] - 1 ) / P );
       }
       arr1[0] = arr1[N];
       arr2[0] = arr2[N];
       arr1[N+1] = arr1[1];
       arr2[N+1] = arr2[1];
        
       BigDecimal denum = BigDecimal.ONE, opop, ans = BigDecimal.ZERO, opop2, opop3, opop4, arr3[] =  new BigDecimal[ 100010 ], arr4[] = new BigDecimal[ 100010 ];
       BigDecimal thou = new BigDecimal( "1000" ), two = new BigDecimal( "2000" );
       for(i=1; i<=N; i++)
       {
    	   opop = new BigDecimal( arr1[i] );
    	   denum = denum.multiply( opop );
       }
       for(i=0; i<=(N+1); i++)
       {
    	   arr3[i] = new BigDecimal( arr1[i] );
    	   arr4[i] = new BigDecimal( arr2[i] );
    	//   System.out.println( arr3[i] + " " + arr4[i] );
       }
       for(i=1; i<=N; i++)
       {
    	   opop = arr4[i].multiply( arr3[i-1] );
    	   opop = opop.multiply( arr3[i+1] );
    	   opop = opop.multiply( two );
    	   
    	   opop2 = arr4[i-1].multiply( arr3[i].subtract( arr4[i] ) );
    	   opop2 = opop2.multiply( arr4[i+1] );
    	   opop2 = opop2.multiply( two );
    	   
    	   opop3 = arr4[i-1].multiply( arr3[i].subtract( arr4[i] ) );
    	   opop3 = opop3.multiply( arr3[i+1].subtract( arr4[i+1] ) );
    	   opop3 = opop3.multiply( thou );
    	   
    	   opop4 = arr4[i+1].multiply( arr3[i].subtract( arr4[i] ) );
    	   opop4 = opop4.multiply( arr3[i-1].subtract( arr4[i-1] ) );
    	   opop4 = opop4.multiply( thou );
    	       	   
    	   opop = opop.add( opop2 );
    	   opop = opop.add( opop3 );
    	   opop = opop.add( opop4 );
    	       	   
    	   ans = ans.add( opop );
       }
       
       ans = ans.divide( denum, 6, BigDecimal.ROUND_HALF_UP );
       
       System.out.println( ans );
	}   
}