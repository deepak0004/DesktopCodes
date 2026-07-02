//package imp;

import java.io.*;
import java.math.*;
import java.util.*;
 
public class sol55
{
    static BigInteger N, A, B, C, ans;
	public static void main( String args[] )
	{
	   Scanner mm = new Scanner( System.in );
       ans = BigInteger.ZERO;  
       
       N = mm.nextBigInteger();
       A = mm.nextBigInteger();
       B = mm.nextBigInteger();
       C = mm.nextBigInteger();
       
       if( A.compareTo( B.subtract(C) ) <= 0 )
       {
    	   System.out.println(  N.divide( A ) );
    	   System.exit(0);
       }
       
       if( N.compareTo(B) >= 0 )
       {
    	   BigInteger lo = new BigInteger( "0" ), hi = new BigInteger( "1223372036854775807" ), mid, tw = new BigInteger( "2" ); 
           while( lo.compareTo(hi)<=0 && lo.compareTo(BigInteger.ZERO)>=0 )
           {
        	   mid = lo.add( hi );
        	   mid = mid.divide( tw );
        	   int gg = binary( mid );
        //	   System.out.println( lo + " " + mid + " " + hi );
        	   if( gg == 1 )
        	   {
        		   ans = mid;
           		   hi = mid.subtract( BigInteger.ONE );
        	   } 
        	   else
        	   {
        		   lo = mid.add( BigInteger.ONE );
        	   }
           }   
       }
       
       N = N.subtract( ans.multiply( B.subtract( C ) ) );
       ans = ans.add( N.divide( A ) );
       
       System.out.println( ans );
	}  
	public static int binary( BigInteger mid )
	{
		BigInteger opop2 = mid.multiply( B.subtract(C) );
		opop2 = opop2.add(B);
	    if( opop2.compareTo(N) > 0 )
	    {
	        return 1;
	    }

	    return 0;
	}
} 
