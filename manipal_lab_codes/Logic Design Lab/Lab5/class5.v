module class5(x,y,Cin,Cout,Sum);
	input[3:0]x,y;
	input Cin;
	output[3:0]Sum;
	output Cout;
	wire[3:0]z,w;
	wire adjust;
	wire co1,co2;
	fourbit_adder fa0(x,y,Cin,co1,z);
	assign adjust = co1|(z[3]&z[2])|(z[3]&z[1]);
	assign Cout = adjust;
	assign w[0] = Cin;
	assign w[3] = Cin;
	assign w[1] = adjust;
	assign w[2] = adjust;
	fourbit_adder fa1(z,w,Cin,co2,Sum);
endmodule
module fourbit_adder(a,b,cin,cout,sum);
	input cin;
	input [3:0]a,b;
	output[3:0]sum;
	output cout;
	wire[4:0]W;
	assign W[0] = cin;
	fulladder fa0(a[0],b[0],W[0],sum[0],W[1]);
	fulladder fa1(a[1],b[1],W[1],sum[1],W[2]);
	fulladder fa2(a[2],b[2],W[2],sum[2],W[3]);
	fulladder fa3(a[3],b[3],W[3],sum[3],W[4]);
	assign cout = W[4];
endmodule
module fulladder(X,Y,CIN,s,c);
	input X,Y,CIN;
	output s,c;
	assign s = X^Y^CIN;
	assign c = (X&Y)|(Y&CIN)|(CIN&X);
endmodule
