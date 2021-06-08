module class3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	assign f = (~a&b)|(b&d)|(~b&~d);
endmodule
