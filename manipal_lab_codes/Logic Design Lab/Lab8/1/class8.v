module MUX_eight(w,s,f);
	input[7:0]w;
	input[3:1]s;
	output f;
	reg f;
	always@(w or s)
	begin
		case(s)
			0: f = w[0];
			1: f = w[1];
			2: f = w[2];
			3: f = w[3];
			4: f = w[4];
			5: f = w[5];
			6: f = w[6];
			7: f = w[7];
		endcase
	end
endmodule
module class8(g,b);
	output [3:0]g;
	input [3:0]b;
	wire [0:7]w3,w2,w1,w0;
	assign w3 = 8'b11110000;                           
	assign w2 = 8'b00111100;
	assign w1 = 8'b01100110;
	assign w0 = {b[0],b[0],b[0],b[0],b[0],b[0],b[0],b[0]};
	MUX_eight m3(w3,b[3:1],g[3]);
	MUX_eight m2(w2,b[3:1],g[2]);
	MUX_eight m1(w1,b[3:1],g[1]);
	MUX_eight m0(w0,b[3:1],g[0]);
endmodule
