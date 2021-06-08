module decoder_3to8(e,x,y,z,f);
	input e,x,y,z;
	output [7:0]f;
	reg [7:0]f;
	always@(e or x or y or z)
	begin
		if(e==1)
		begin
			if(x==0)
			begin
				if(y==0)
				begin
					if(z==0)
						f = 8'b00000001;
					else
						f = 8'b00000010;
				end
				else
				begin
					if(z==0)
						f = 8'b00000100;
					else
						f = 8'b00001000;
				end
			end
			else
			begin
				if(y==0)
				begin
					if(z==0)
						f = 8'b00010000;
					else
						f = 8'b00100000;
				end
				else
				begin
					if(z==0)
						f = 8'b01000000;
					else
						f = 8'b10000000;
				end
			end
		end
		else
		begin
			f = 8'b00000000;
		end 
	end
endmodule
module class10(En,X,Y,Z,F1,F2,F3);
	input En,X,Y,Z;
	output F1,F2,F3;
	wire [7:0]F;
	decoder_3to8 d(En,X,Y,Z,F);
	assign F1 = F[0] | F[5] | F[7];
	assign F2 = F[2] | F[3] | F[4];
	assign F3 = F[1] | F[6] | F[7];	
endmodule
