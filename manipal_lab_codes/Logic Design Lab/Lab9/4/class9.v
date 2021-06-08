module class9(w,f,e);
	input [3:0]w;
	input e;
	output [15:0]f;
	wire e1,e2;
	assign e1 = ~w[3]&e;
	assign e2 = w[3]&e;
	Decoder_8to3 d1(w[2:0],f[7:0],e1);
	Decoder_8to3 d2(w[2:0],f[15:8],e2);
endmodule
module Decoder_8to3(W,F,E);
	input [2:0]W;
	input E;
	output [7:0]F;
	reg [7:0]F;
	always@(W or E)
	begin
		case(E)
			1:
			begin
				case(W)
					3'b000:	F = 8'b00000001;
					3'b001:	F = 8'b00000010;
					3'b010:	F = 8'b00000100;
					3'b011:	F = 8'b00001000;
					3'b100:	F = 8'b00010000;
					3'b101:	F = 8'b00100000;
					3'b110:	F = 8'b01000000;
					3'b111:	F = 8'b10000000;
				endcase
			end
		endcase
	end
endmodule

