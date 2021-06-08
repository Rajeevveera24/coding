module class4(x,f);
	input [1:4]x;
	output f;
	wire a,b;
	assign a = ~x[3]&~x[4];
	assign b = x[1]&x[2];
	assign f = (a&~b) | (~a&b);
endmodule
