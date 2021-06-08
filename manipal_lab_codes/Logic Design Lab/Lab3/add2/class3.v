module class3(x1,x2,x3,x4,f);
	input x1,x2,x3,x4;
	output f;
	not(a,x1);
	not(b,x2);
	not(c,x3);
	or(p,a,x3);
	or(q,x1,b,c,x4);
	and(f,p,q);
endmodule
