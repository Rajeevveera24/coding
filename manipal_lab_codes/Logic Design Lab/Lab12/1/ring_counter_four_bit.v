module decoder_2to4(s,f);
	input [1:0]s;
	output [3:0]f;
	reg [3:0]f;
	always@(s)
	begin
		if(s[1] == 0)
		begin
			if(s[0] == 0)
				f = 4'b0001;
			else
				f = 4'b0010;
		end
		else
		begin
			if(s[0] == 0)
				f = 4'b0100;
			else
				f = 4'b1000;
		end
	end
endmodule
module tff1(T,Clk,Q);
	input T,Clk;
	output Q;
	reg Q;
	always@(negedge Clk)
		Q<=Q^T;
endmodule
module twobit(Clock,q);
	input Clock;
	output [1:0]q;
	tff1 f1(1,Clock,q[0]);
	tff1 f2(1,q[0],q[1]);
endmodule
module ring_counter_four_bit(clk,Counter);
	input clk;
	output [3:0]Counter;
	wire [1:0]w;
	twobit t(clk,w);
	decoder_2to4 d(w,Counter);
endmodule
