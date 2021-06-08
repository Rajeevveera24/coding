module n_bit_shift_register(In,Clk,Reg);
	parameter n = 4;
	integer k;
	input In,Clk;
	output[1:n]Reg;
	reg [1:n]Reg;
	always@(posedge Clk)
	begin
		for(k=n-1;k>0;k=k-1)
			Reg[k+1] = Reg[k];
		Reg[1] = In;
	end
endmodule
