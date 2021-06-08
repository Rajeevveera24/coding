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
module class10(A,B,C,En,f);
	input A,B,C,En;
	output f;
	wire [7:0]Y;
	wire [2:0]X;
	assign X[2] = A;
	assign X[1] = B;
	assign X[0] = C;
	Decoder_3to8 D(X,Y,En);
	assign f = Y[0]|Y[2]|Y[3]|Y[4]|Y[5]|Y[7];
endmodule
