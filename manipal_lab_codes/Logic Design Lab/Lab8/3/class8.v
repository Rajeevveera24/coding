module class8(a,b,c,f1,f2);
	input a,b,c;
	output f1,f2;
	reg [0:1]w1,w2;
	reg f1,f2;
	always@(a or b or c)
	begin
		w1[0] = ~c|~b;
		w1[1] = c;
		w2[0] = ~b;
		w2[1] = (~b&~c)|(b&c);
		if(a==0)
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
endmodule
