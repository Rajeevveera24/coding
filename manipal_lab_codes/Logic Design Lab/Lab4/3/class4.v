module class4(a,b,c,d,f,g);
	input a,b,c,d;
	output f,g;	
	wire h;
	assign  h = (~a&~c&~d)|(~b&c&~d)|(a&~b&~c&d);
	assign f = h | (~a&b&c);
	assign g = h|(a&b&c);
endmodule
