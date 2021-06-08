module class3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	not(b1,b);
	not(d1,d);
	not(c1,c);
	and(p,a,b,c1,d);
	and(q,b1,d1);
	and(r,c,d1);
	or(f,p,q,r);
endmodule


