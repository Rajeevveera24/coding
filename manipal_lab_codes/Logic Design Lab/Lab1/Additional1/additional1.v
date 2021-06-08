module additional1(x1,x2,x3,x4,f);
	input x1,x2,x3,x4;
	output f;
	and (a,x1,x3);
	and (b,x2,x3);
	and (c,x3,x4);
	and (d,x1,x2);
	and (e,x1,x4);
	or (f,a,b,c,d,e);
endmodule
