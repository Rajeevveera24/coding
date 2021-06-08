module class3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	not (a1,a);
	not(b1,b);
	not(d1,d);
	and(p,a1,b);
	and(q,b1,d1);
	and(r,b,d);
	or(f,p,q,r);
endmodule
