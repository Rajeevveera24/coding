module grey_to_bin(grey,bin);
	parameter n=4;
	input[n-1:0]grey;
	output[n-1:0]bin;
	reg [n-1:0]bin;
	integer k;
	always@(grey)
	begin
		bin[n-1]=grey[n-1];
		for(k=n-2;k>=0;k=k-1)
		begin
			bin[k] = bin[k+1] ^ grey[k];
		end
	end		
endmodule
