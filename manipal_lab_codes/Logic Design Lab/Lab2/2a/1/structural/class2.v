module class2(a,b,c,y);
	input a,b,c;
	output y;
	and (d,a,b);
	and (e,b,c);
	and (f,c,a);
	or (y,d,e,f);
endmodule
