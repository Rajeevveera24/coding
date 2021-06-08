module fulladder(x,y,cin,sum,cout);
	input x,y,cin;
	output sum,cout;
	xor(s,x,y);
	xor(sum,s,cin);
	assign cout = (x&y)|(y&cin)|(cin&x);
endmodule
module ripple_carry_adder(x,y,cin,Sum,Cout);
	input [3:0]x,y;
	input cin;
	output [3:0]Sum;
	output Cout;
	wire[4:0]c;
	assign c[0] = cin;
	xor(y0,y[0],c[0]);
	xor(y1,y[1],c[0]);
	xor(y2,y[2],c[0]);
	xor(y3,y[3],c[0]);
	fulladder fa0(x[0],y0,c[0],Sum[0],c[1]);
	fulladder fa1(x[1],y1,c[1],Sum[1],c[2]);
	fulladder fa2(x[2],y2,c[2],Sum[2],c[3]);
	fulladder fa3(x[3],y3,c[3],Sum[3],c[4]);
	assign Cout = c[4];
endmodule
