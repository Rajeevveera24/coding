module class8(a,b,c,d,f1,f2);
	input a,b,c,d;
	output f1,f2;
	reg [0:3]w1,w2;
	reg f1,f2;
	always@(a or b or c or d)
	begin
		w2[0] = ~c;
		w2[1] = 1'b1;
		w2[2] = 1'b0;
		w2[3] = ~c;
		w1[0] = d;
		w1[1] = c^d;
		w1[2] = d;
		w1[3] = 1'b0;
		if(a==0)
		begin
			if(b==0)
			begin
				f1 = w1[0];
				f2 = w2[0];
			end
			else
			begin
				f1 = w1[1];
				f2 = w2[1];
			end
		end
		else
		begin
			if(b==0)
			begin
				f1 = w1[2];
				f2 = w2[2];
			end
			else
			begin
				f1 = w1[3];
				f2 = w2[3];
			end
		end
	end
endmodule
			



