module class9(w,f);
	input [7:0]w;
	output [2:0]f;
	integer k;
	reg [2:0]f;
	always@(w or k)
	begin
		for(k=0;k<8;k=k+1)
			if(w[k]==1)
				f=k;
	end
endmodule
