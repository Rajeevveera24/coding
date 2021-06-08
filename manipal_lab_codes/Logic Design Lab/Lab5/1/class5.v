module halfadder(x,y,sum,carry);
	input x,y;
	output sum,carry;
	assign sum = x^y;
	assign carry = x&y;
endmodule
module class5(x,y,Sum,Cin,Cout);
	input x,y,Cin;
	output Cout,Sum;
	halfadder ha0(x,y,s1,c1);
	halfadder ha1(s1,Cin,Sum,c2);
	or(Cout,c1,c2);
endmodule
