module class1(x1,x2,x3,x4,f,g,h);
	input x1,x2,x3,x4;
	output f,g,h;
	assign g= (x1 & x3) | (x2 & x4);
	assign h = (~x3 | x1) & (~x2 | x4);
	assign f = g|h;
endmodule
	
