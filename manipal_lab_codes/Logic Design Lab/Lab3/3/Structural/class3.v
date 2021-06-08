module class3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	or(p,b,d);
	not(d1,d);
	not(a1,a);
	not(c1,c);
	or(q,b,c1);
	or(r,a1,c,d1);
	or(s,a,c1,d1);
	and(f,p,q,r,s);
endmodule

