module class2(x,y,z,p,q);
	input x,y,z;
	output p,q;
	or(a,y,z);
	and (p,x,a);
	and(b,x,y);
	and(c,x,z);
	or(q,b,c);
endmodule

