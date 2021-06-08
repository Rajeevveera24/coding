module class2(f,x,y,z);
	input x,y,z;
	output f;
	nor (a,x,x);
	nor (b,a,z);
	nor (c,b,y);
	nor (f,c,c);
endmodule
