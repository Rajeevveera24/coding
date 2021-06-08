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
	fulladder fa0(x[0],y[0],c[0],Sum[0],c[1]);
	fulladder fa1(x[1],y[1],c[1],Sum[1],c[2]);
	fulladder fa2(x[2],y[2],c[2],Sum[2],c[3]);
	fulladder fa3(x[3],y[3],c[3],Sum[3],c[4]);
	assign Cout = c[4];
endmodule
module BCD_adder(x,y,adj0,adj3,Sum,Cin,cin,Carry);
	input [3:0]x,y;
	inout Cin,adj0,adj3,cin;
	output [3:0]Sum;
	output Carry;
	wire [3:0]z;
	ripple_carry_adder rca1(x,y,Cin,z,cout);
	and(a,z[3],z[2]);	
	and(b,z[3],z[1]);
	or(adj1,a,b,cout);
	wire[3:0]adj;
	assign adj[3] = adj3;
	assign adj[0] = adj0;
	assign adj[1] = adj1;
	assign adj[2] = adj1;
	ripple_carry_adder rca2(z,adj,cin,Sum,Carry);
endmodule
	

