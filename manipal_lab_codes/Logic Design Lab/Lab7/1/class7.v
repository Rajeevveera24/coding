module class7(w,s,f);
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
