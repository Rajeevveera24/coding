module class9(w,f);
	input [7:0]w;
	output [2:0]f;
	reg [2:0]f;
	always@(w)
	begin
		casex(w)
			8'b1xxxxxxx:	f=3'b111;
			8'b01xxxxxx:	f=3'b110;
			8'b001xxxxx:	f=3'b101;
			8'b0001xxxx:	f=3'b100;
			8'b00001xxx:	f=3'b011;
			8'b000001xx:	f=3'b010;
			8'b0000001x:	f=3'b001;
			8'b00000001:	f=3'b000;
		endcase
	end
endmodule
