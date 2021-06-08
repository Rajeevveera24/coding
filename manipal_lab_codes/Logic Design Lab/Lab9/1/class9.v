module class9(w,e,f);
	input [2:0]w;
	input e;	
	output [7:0]f;
	reg [7:0]f;
	always@(w or e)
	begin 
		case(e)
			1:
			begin
				case(w)
					3'b000: f = 8'b11111110;
					3'b001:	f = 8'b11111101;
					3'b010:	f = 8'b11111011;
					3'b011:	f = 8'b11110111;
					3'b100:	f = 8'b11101111;
					3'b101:	f = 8'b11011111;
					3'b110:	f = 8'b10111111;
					3'b111:	f = 8'b01111111;
				endcase
			end
		endcase
	end
endmodule
