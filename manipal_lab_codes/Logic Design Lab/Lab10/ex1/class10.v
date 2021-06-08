module Decoder_3to8(W,F,E);
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
					3'b001: F = 8'b00000010;
					3'b010:	F = 8'b00000100;
					3'b011:	F = 8'b00001000;
					3'b100:	F = 8'b00010000;
					3'b101:	F = 8'b00100000;
					3'b110:	F = 8'b01000000;
					3'b111:	F = 8'b10000000;
				endcase
			end
			0:F = 8'b00000000;
		endcase
	end
endmodule
module class10(A,B,C,F1,F2,F3);
	input A,B,C;
	output F1,F2,F3;
	wire [7:0]f;
	wire [2:0]w;
	assign w[2] = A;
	assign w[1] = B;
	assign w[0] = C;
	Decoder_3to8 d(w,f,1'b1);
	assign F1 = f[2] | f[4] | f[7];
	assign F2 = f[0] | f[3];
	assign F3 = F1 | F2;
endmodule
