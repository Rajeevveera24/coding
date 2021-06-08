module bin_to_grey(bin,grey);
	parameter n =4;
	input[n-1:0]bin;
	output[n-1:0]grey;
	reg[n-1:0]grey;
	integer k;
	always@(bin)
	begin
		grey[n-1] = bin[n-1];
		for(k=n-2;k>=0;k=k-1)
		begin
			grey[k] = bin[k+1] ^ bin[k];
		end
	end
endmodule
