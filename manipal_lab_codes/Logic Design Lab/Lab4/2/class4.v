module class4(a,b,c,d,f);
	input a,b,c,d;
	output f;
	nand(p,b,b);
	nand(q,p,a);
	nand(f,d,q);
endmodule
	
