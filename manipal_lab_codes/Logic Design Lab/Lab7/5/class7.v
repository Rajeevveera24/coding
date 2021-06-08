module class7(s,w,f);
	input [1:0]s;
	input [3:0]w;
	output f;
	function mux2to1;
		input[1:0]w;
		input s;
		if(s==0)
			mux2to1 = w[0];
		else
			mux2to1 = w[1];
	reg f;
	reg [1:0]wi;
	function mux2to1;
		input[1:0]w;
		input s;
		if(s==0)
			mux2to1 = w[0];
		else
			mux2to1 = w[1];
	endfunction
	always@(s or w)
	begin
		wi[0] = mux2to1(w[0:1],s[0]);
		wi[1] = mux2to1(w[2:3],s[0]);
		f = mux2to1(wi,s[1]);
	end
endmodule
