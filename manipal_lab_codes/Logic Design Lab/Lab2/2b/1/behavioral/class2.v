module class2(f,x,y,z);
	input x,y,z;
	output f;
	assign f = ~(~((~((~(x|x))|z))|y)|~((~((~(x|x))|z))|y));
endmodule
