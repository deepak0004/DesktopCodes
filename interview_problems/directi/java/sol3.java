package imp;

import java.io.*;
import java.math.*;
import java.util.*;
 
class sol3
{
	static BigInteger[] height = new BigInteger[100010];
    static BigInteger[] rate = new BigInteger[100010];
    static int N;
    static BigInteger W;
	static BigInteger L;
	public static void main( String args[] )
	{
	   Scanner mm = new Scanner( System.in );
       
	   int i; 
       
       N = mm.nextInt();
       W = mm.nextBigInteger();;
       L = mm.nextBigInteger();
       for(i=0; i<N; i++)
       {
    	   height[i] = mm.nextBigInteger();
    	   rate[i] = mm.nextBigInteger();
       }
       
       BigInteger lo = new BigInteger( "0" ), hi = new BigInteger( "1223372036854775807" ), mid, tw = new BigInteger( "2" ), ans = BigInteger.ZERO; 
       while( lo.compareTo(hi)<=0 && lo.compareTo(BigInteger.ZERO)>=0 )
       {
    	  // System.out.println( ans );
    	   mid = lo.add( hi );
    	   mid = mid.divide( tw );
    	   int gg = binary( mid );
    	  // System.out.println( mid );
    	   if( gg == 1 )
    	   {
    		   ans = mid;
    		   hi = mid.subtract(BigInteger.ONE);
    	   } 
    	   else
    	   {
       		   lo = mid.add(BigInteger.ONE);
    	   }
       }
       
       System.out.println( ans );
	}  
	public static int binary( BigInteger mid )
	{
		int i;
		BigInteger mk = BigInteger.ZERO, anss = BigInteger.ZERO;
		for(i=0; i<N; i++)
		{
			mk = ( rate[i].multiply( mid ) );
			mk = mk.add( height[i] );
			if( mk.compareTo(L)>=0 )
			{
				//System.out.println( anss );
				anss = anss.add( mk );
			}
		}
		if( anss.compareTo( W )>=0 )
		{
			return 1;
		}
		return 0;
	}
} 
