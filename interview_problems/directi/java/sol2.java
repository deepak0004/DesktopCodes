package imp;

// On codeforces
// There should be no package while submitting and class should be made public.
import java.io.*;
import java.math.*;
import java.util.*;

public class sol2
{
    public static void main( String args[] )
    {
       Scanner mm = new Scanner( System.in );
       
       BigInteger T, W, B, i, j;
       T = mm.nextBigInteger();
       W = mm.nextBigInteger();
       B = mm.nextBigInteger();
       
       BigInteger opop = W.multiply( B );
       opop = opop.divide( W.gcd(B) );
       BigInteger time = T.divide( opop );
       BigInteger time2 = W.min( B );
       BigInteger opop3 = W.min( B );
       opop3 = opop3.subtract( BigInteger.ONE );
      
       time = time.multiply( time2 );
     //  System.out.println( time2 );
       
       if( T.remainder( opop ) != BigInteger.ZERO )
       {
           time = time.add( opop3.min( T.remainder( opop ) ) );
       }                                             
                                                             
       BigInteger opop4 = T.gcd( time );                                     
                                                             
       time = time.divide( opop4 ); 
       T = T.divide( opop4 );
       
       System.out.println( time + "/" + T );
     }  
}           