module class2(f,x1,x2,x3);
	input x1,x2,x3;
	output f;
	nand (a,x1,x1);
	nand (b,x2,x2);
	nand (c,a,b);
	nand (d,x1,x3);
	nand (e,c,d);
	nand (f,e,e);
endmodule	
