module class1(D,Clock,Resetn,Q);
	input D,Clock,Resetn;
	output Q;
	reg Q;
	always@(negedge Clock or negedge Resetn)
	if(!Resetn)
		Q<=0;
	else
		Q<=D;
endmodule
