module class2(a,p,q);
	input a;
	output p,q;
	assign p = ~(~a);
	assign q = a;
endmodule

