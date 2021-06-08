module class7(w,s,f);
	input [1:0]s;
	input [3:0]w;
	output f;
	reg f;
	always @ (w or s)
	begin
		assign f = s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
	end
endmodule
