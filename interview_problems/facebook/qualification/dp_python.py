# deepak2015
import numpy
from decimal import Decimal

f = open('input.txt')
f2 = open('output.txt', 'w')

dp =  numpy.zeros( (24, 24, 428) )
for ppll in range(1, 21):
    dp[ppll][0][0] = 1
for ppll in range(1, 21):
    for i in range(1, 21):
      for j in range(1, 20*ppll + 2):
          for k in range(1, ppll+1):
              if( (j-k)>=0 ):
                 dp[ppll][i][j] += dp[ppll][i-1][j-k]
for ppll in range(1, 21):
    for i in range(1, 21):
      for j in range(1, 20*ppll + 2):
              dp[ppll][i][j] += dp[ppll][i][j-1]

T = int(f.readline().strip())
T = int(T);

for c in range(1, T+1):
       res = 0.0
       H, S = f.readline().strip().split(' ');
       H = int(H);
       S = int(S);
	
       edge = f.readline().strip().split(' ');
       for i in range(0, S):
           X, Y = edge[i].split('d');
           if( "+" in Y ):
               Y, Z = Y.split('+')
               Y = int(Y)
               Z = int(Z)
           elif( "-" in Y ):
               Y, Z = Y.split('-')
               Y = int(Y)
               Z = (-1)*int(Z)    
           else:
               Y = int(Y)
               Z = 0
           X = int(X)
           '''
           if( c==3 ):
               print(X, end = " ")
               print(Y, end = " ")
               print(Z)
           '''
           if( Z>=H ):
               res = 1.0
           elif( ( (Y*X) + Z )<H ):
               continue
           else:
               '''
               print(c, end=" ")
               print(i)
               '''
               opop = max(H-Z-1, 0)
               anss = dp[Y][X][opop]
               anss = Decimal( anss ) / Decimal(pow(Y, X))
               anss = Decimal(1) - anss
               res = max(res, anss)
               
       st = "Case #" + str(c) + ": "
       f2.write( str(st) )
       st = "%.9f" %res
       f2.write( str(st) )
       f2.write( "\n" )
       
f2.close()