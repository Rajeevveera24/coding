module D_flipflop(Q,D,Clk);
	input D,Clk;
	output Q;
	reg Q;
	always@(posedge Clk)
		Q<=D;
endmodule
module register_8_bit(clk,f,r);
	input [7:0]f;
	input clk;
	output [7:0]r;
	D_flipflop d0(r[0],f[0],clk);
	D_flipflop d1(r[1],f[1],clk);
	D_flipflop d2(r[2],f[2],clk);
	D_flipflop d3(r[3],f[3],clk);
	D_flipflop d4(r[4],f[4],clk);
	D_flipflop d5(r[5],f[5],clk);
	D_flipflop d6(r[6],f[6],clk);
	D_flipflop d7(r[7],f[7],clk);
endmodule
