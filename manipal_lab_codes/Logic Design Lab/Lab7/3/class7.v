module class7(s,w,f);
	input [1:0]s;
	input [3:0]w;
	output f;
	reg f;
	always @ (s or w)
	begin
		if(s[1] == 0)
		begin
			if(s[0] == 0)
				f = w[0];
			else
				f = w[1];
		end
		else
		begin
			if(s[0] == 0)
				f = w[2];
			else
				f = w[3];
		end
	end
endmodule
			
	
