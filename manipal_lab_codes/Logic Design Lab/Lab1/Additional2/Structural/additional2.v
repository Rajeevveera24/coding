module additional2(x1,x2,x3,x4,f);
	input x1,x2,x3,x4;
	output f;
	or (a,x1,x3);
	or (b,x1,x2,x4);
	or (c,x2,x3,x4);
	and (f,a,b,c);
endmodule
