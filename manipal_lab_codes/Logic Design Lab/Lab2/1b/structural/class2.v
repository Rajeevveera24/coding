module class2(x,y,z,p,q);
	input x,y,z;
	output p,q;
	and (a,y,z);
	or (p,x,a);
	or (b,x,y);
	or (c,x,z);
	and (q,b,c);
endmodule
