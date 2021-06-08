module class3(a,b,c,f);
	input a,b,c;
	output f;
	and(p,a,b);
	and(q,b,c);
	and(r,c,a);
	or(f,p,q,r);
endmodule
