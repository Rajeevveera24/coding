module pos_edge_D(Clk,D,Q);
	input Clk,D;
	output Q;
	reg Q;
	always@(posedge Clk)
		Q = D;
endmodule
module counter_johnson(clk,Reg,T0,T1,T2,T3,T4,T5,T6,T7);
	input clk;
	output [0:3]Reg;
	output T0,T1,T2,T3,T4,T5,T6,T7;	
	wire A,B,C,D;
	pos_edge_D d0(clk,~Reg[3],Reg[0]);
	pos_edge_D d1(clk,Reg[0],Reg[1]);
	pos_edge_D d2(clk,Reg[1],Reg[2]);
	pos_edge_D d3(clk,Reg[2],Reg[3]);
	assign A = Reg[0];
	assign B = Reg[1];
	assign C = Reg[2];
	assign D = Reg[3];
	assign T0 = ~A&~D;
	assign T1 = A&~B;
	assign T2 = B&~C;
	assign T3 = C&~D;
	assign T4 = A&D;
	assign T5 = ~A&B;
	assign T6 = ~B&C;
	assign T7 = ~C&D;
endmodule
	
