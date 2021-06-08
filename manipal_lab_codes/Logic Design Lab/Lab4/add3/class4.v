module class4(x,f);
	input [1:5]x;
	output f;
	assign f = (x[5]&(~x[1]|x[2])&((~x[3]&~x[4])|(x[3]&x[4])))|((~x[3]&x[4])&((x[1]&~x[2])|(~x[1]&~x[5])));
endmodule
