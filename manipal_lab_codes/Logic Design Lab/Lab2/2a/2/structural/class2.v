module class2(y,a,b,c);
	input a,b,c;
	output y;
	nand (d,a,b);	
	nand (e,b,c);
	nand (f,c,a);
	nand (y,d,e,f);
endmodule
