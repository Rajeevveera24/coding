module four_bit_async_up_counter(Clk,Count);
	input Clk;
	output [3:0]Count;
	neg_edge_JK jk0(Clk,1,1,Count[0]);
	neg_edge_JK jk1(Count[0],1,1,Count[1]);
	neg_edge_JK jk2(Count[1],1,1,Count[2]);
	neg_edge_JK jk3(Count[2],1,1,Count[3]);
endmodule
module neg_edge_JK(clk,J,K,Q);
	input clk,J,K;
	output Q;
	reg Q;
	always@(negedge clk)
		Q = ~Q&J | Q&~K;
endmodule
