module multiplier(x,y,Cin,m,C);
	input [1:0]x,y;
	input Cin;
	output [0:3]m;
	output C;
	and(a,x[0],y[0]);
	halfadder ha1(a,Cin,m[0],Cin);
	and (b,x[1],y[0]);
	and (e,x[0],y[1]);
	halfadder ha2(b,e,m[1],C);
	and(d,x[1],y[1]);
	halfadder ha3(d,C,m[2],m[3]);
endmodule
module halfadder(x,y,s,c);
	input x,y;
	output s,c;
	assign s = x ^ y;
	assign c = x&y;
endmodule
