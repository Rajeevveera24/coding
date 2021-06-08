module class4(a,b,c,d,f);
	input a,b,c,d;
	output f;
	nor(d1,d,d);
	nor(p,a,d1);
	nor(q,b,d);
	nor(f1,p,q);
	nor(f,f1,f1);
endmodule
