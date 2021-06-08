module ftoo(w,s,f);
	input [1:0]s;
	input [3:0]w;
	output f;
	assign f = s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
endmodule
module class7(W,S,F);
	input [15:0]W;	
	input [3:0]S;
	output F;
	wire [3:0]w1;
	ftoo f1(W[3:0],S[1:0],w1[0]);
	ftoo f2(W[7:4],S[1:0],w1[1]);
	ftoo f3(W[11:8],S[1:0],w1[2]);
	ftoo f4(W[15:12],S[1:0],w1[3]);
	ftoo f5(w1,S[3:2],F);
endmodule
