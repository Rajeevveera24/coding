module class1(x1,x2,x3,x4,g,f,h);
	input x1,x2,x3,x4;
	output g,f,h;
	and (a,x1,x3);
	and (b,x2,x4);
	or (g,a,b);
	not (d,x3);
	not (e,x2);
	or (i,d,x1);
	or (j,e,x4);
	and (h,i,j);
	or (f,h,g);
endmodule
