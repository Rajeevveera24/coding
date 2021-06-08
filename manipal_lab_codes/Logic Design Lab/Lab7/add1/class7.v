module class7(s,w,f);
	input[2:0]s;
	input[7:0]w;
	output f;
	reg f;
	always@(s or w)
	begin
		if(s[2]==0)
		begin
			if(s[1]==0)
			begin
				if(s[0]==0)
					f = w[0];
				else
					f = w[1];
			end
			else
			begin
				if(s[0]==0)
					f = w[2];
				else
					f = w[3];
			end
		end
		else
		begin
			if(s[1]==0)
			begin
				if(s[0]==0)
					f = w[4];
				else
					f = w[5];
			end
			else
			begin
				if(s[0]==0)
					f = w[6];
				else
					f = w[7];
			end
		end
	end
endmodule



