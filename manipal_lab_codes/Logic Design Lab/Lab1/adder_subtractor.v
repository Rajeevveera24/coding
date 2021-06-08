module fulladder(a,b,Cin,S,C);
	input a,b,Cin;
	output S,C;
	xor(s1,a,b);
	xor(S,s1,Cin);
	and(c1,a,b);
	and(C,c1,Cin);
endmodule
module adder_subtractor(x,y,);
