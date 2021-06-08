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
module class10(w,S,F);
	input [1:0]S;
	input [3:0]w;
	output	F;
	integer k;
	reg F;
	wire [3:0]F1;
	decoder_2to4 d(S,F1);
	always@(F1 or w)
	begin
		for(k=0;k<4;k=k+1)
		begin
			if(F1[k]== 1)
				F = w[k];
		end
	end
endmodule
