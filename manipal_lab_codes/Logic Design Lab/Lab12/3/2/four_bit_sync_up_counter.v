module pos_edge_sync_JK(clk,J,K,Q);
	input clk,J,K;
	output Q;
	reg Q;
	always@(posedge clk)
		Q <= J&~Q|~K&Q;
endmodule
module four_bit_sync_up_counter(Clk,Counter);
	input Clk;
	output [3:0]Counter;
	wire enable;
	assign enable = 1;
	pos_edge_sync_JK jk0(Clk,1,1,Counter[0]);
	pos_edge_sync_JK jk1(Clk,enable&Counter[0],enable&Counter[0],Counter[1]);
	pos_edge_sync_JK jk2(Clk,enable&Counter[0]&Counter[1],enable&Counter[0]&Counter[1],Counter[2]);
	pos_edge_sync_JK jk3(Clk,enable&Counter[0]&Counter[1]&Counter[2],enable&Counter[0]&Counter[1]&Counter[2],Counter[3]);
endmodule 
