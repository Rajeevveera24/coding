module class4(a,b,c,d,f);
	input a,b,c,d;
	output f;
	nand(a1,a);
	nand(d1,d);
	nand(p,c,d1);
	nand(q,a1,d1);
	nand(r,b,d1);
	nand(s,a1,b,c);
	nand(f,p,q,r,s);
endmodule
