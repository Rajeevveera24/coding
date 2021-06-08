module class4(a,b,c,d,f);
	input a,b,c,d;
	output f;
	nor(a1,a,a);
	nor(b1,b,b);
	nor(c1,c,c);
	nor(d1,d,d);
	nor(p,a1,c1);
	nor(q,b1,c1);
	nor(r,b1,d1);
	nor(f,p,q,r);
endmodule
