module class2 (f,x,y,z);
	input x,y,z;
	output f;
	nand (a,z,z);
	nand (b,x,z);
	nand (c,y,y);
	nand (f,b,c);
endmodule
