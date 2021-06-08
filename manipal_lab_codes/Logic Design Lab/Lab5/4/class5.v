module class5(x,y,Cin,m,Cout);
	input[1:0]x,y;
	input Cin;
	output[3:0]m;
	output Cout;
	and(a,x[0],y[0]);
	halfadder ha1(a,Cin,m[0],Cin);
	and(b,x[1],y[0]);
	and(e,x[0],y[1]);
	halfadder ha2(b,e,m[1],Cout);
	and(d,x[1],y[1]);
	halfadder ha3(d,Cout,m[2],m[3]);
endmodule
module halfadder(X,Y,s,c);
	input X,Y;
	output s,c;
	assign s = X^Y;
	assign c = X&Y;
endmodule
