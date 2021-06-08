module fulladder(x,y,cin,sum,cout);
	input x,y,cin;
	output sum,cout;
	xor(s,x,y);
	xor(sum,s,cin);
	assign cout = (x&y)|(y&cin)|(cin&x);
endmodule
module FourAdder(x,y,Cin,Sum,Cout);
	input[3:0]x,y;
	input Cin;
	output[3:0]Sum;
	output Cout;
	wire[4:0]C;
	assign C[0]=Cin;
	fulladder fa0(x[0],y[0],C[0],Sum[0],C[1]);
	fulladder fa1(x[1],y[1],C[1],Sum[1],C[2]);
	fulladder fa2(x[2],y[2],C[2],Sum[2],C[3]);
	fulladder fa3(x[3],y[3],C[3],Sum[3],C[4]);
	assign Cout = C[4];
endmodule
module class5(Summ,CarryOut);
	output [4:1]Summ;
	input [4:1]A,B;
	input CarryIn,d1,d2,d3,d4;
	FourAdder F1(A,B,CarryIn,Summ1,CO);
	wire h;
	assign h = (Summ1[3]&Summ1[2])|(Summ1[3]&Summ1[1])|CO;
	assign 
	
