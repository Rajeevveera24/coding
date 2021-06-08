module class2(x1,x2,x3,f);
	input x1,x2,x3;
	output f;
	nor (a,x1,x1);
	nor (b,x3,x3);
	nor (c,x1,x2);
	nor (d,a,b);
	nor (f,c,d);
endmodule
	  
