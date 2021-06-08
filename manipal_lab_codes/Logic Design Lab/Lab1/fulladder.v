module halfadder(x,y,s,c);
	input x,y;
	output s,c;
	assign s = x ^ y;
	assign c = x&y;
endmodule
module fulladder(a,b,Cin,S,C);
	input a,b,Cin;
	output S,C;
	halfadder ha1(a,b,s,c);
	halfadder ha2(Cin,s,S,c1);
	or(C,c,c1);
endmodule
