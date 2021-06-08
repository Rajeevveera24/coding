module class6(x,y,c,Sum,Over);
	parameter n = 4;
	input[n-1:0]x,y;
	input c;
	output[n-1:0]Sum;
	reg[n-1:0]Sum;
	output Over;
	reg[n:0]carry;
	integer k;
	always@(x|y)
	begin
		carry[0] = c;
		Sum[0] = x[0]^y[0]^carry[0]; 
		for(k=1;k<n;k=k+1)
		begin
			carry[k] = (x[k-1]&y[k-1])|(y[k-1]&carry[k-1])|(carry[k-1]&x[k-1]);
			Sum[k] = x[k]^y[k]^carry[k];
		end
		carry[n] = (x[n-1]&y[n-1])|(y[n-1]&carry[n-1])|(carry[n-1]&x[n-1]);
	end
	assign Over = carry[n] ^ carry[n-1];
endmodule
