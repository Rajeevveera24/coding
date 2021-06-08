module class2 (f,x,y,z);
	input x,y,z;
	output f;
	assign f = ~((~(x&(~(z&z))))&(~(y&y)));
endmodule
