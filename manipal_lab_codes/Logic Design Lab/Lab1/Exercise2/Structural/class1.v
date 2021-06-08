module class1(x1,x2,x3,f);
	input x1,x2,x3;
	output f;
	or (a,x1,x2,x3);
	not (b,x3);
	not (c,x2);
	not (d,x1);
	or (e,x3,c,d);
	or (g,x2,d,b);
	or (h,x1,b,c);
	and (f,a,e,g,h);
	
endmodule
