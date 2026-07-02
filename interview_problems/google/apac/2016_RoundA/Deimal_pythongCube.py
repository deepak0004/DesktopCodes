#Chalubhalu
#Mrinal Ahlawat
from decimal import Decimal
t = raw_input()
t = int(t);
for c in range(1,t+1) :
	print "Case #"+str(c)+":";
	n, m = raw_input().split(' ');
	n = int(n);
	m = int(m);
	edge = raw_input().split(' ');
	for i in range(0,n):
		edge[i] = int(edge[i]);
	while m > 0 :
		m = m-1;
		l,r = raw_input().split(' ');
		l = int(l);
		r = int(r);
		vol = Decimal(1);
		for i in range(l,r+1):
			vol = vol * edge[i];
		print "%.9f" % pow(vol,Decimal(1.0/(r-l+1)));